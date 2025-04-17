#include <stdio.h>
#include <stdlib.h>
#include "Astar.h"
#include "stdafx.h"

extern PLAYER player;
extern ENEMY enemy;
extern int enemyNum;
extern ENEMY enemysPos[10];


extern QUEUE* Q[10];
extern VERTEX s[10];
extern VERTEX e;	// start, end

extern QUEUE* f[10];
extern QUEUE** newq[10];
extern int count[10];
extern int size[10];

int cnt = 0;

typedef enum MapType
{
	WALL = 1,
	COIN = 2,
	MAX
} MapType;

typedef enum VistType
{
	WALL = -2,
	MAX
} VisitType;

void UpdateFPS()
{
	static float timeElapsed = 0.0f;			
	DWORD curTime = clock();					
	timeElapsed += (curTime - lastTime);

	MapType wall = WALL;
	VisitType visitWall = WALL;

	if(timeElapsed >= 1000.0f)
	{
		FreeAndResetMemory();
		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			for (int z = 0; z < MAPSIZE_X; z++)
			{
				if (map[j][z] == wall)
					visit[cnt][j][z] = visitWall;	// WALL = -2
			}
		}

		astar(pre[cnt], &s[cnt], visit[cnt], &Q[cnt], g[cnt], &e, cnt);
		print_character(cnt);

		if (cnt + 1 < enemyNum)
			cnt++;
		else cnt = 0;

		timeElapsed = 0.0f;
	}

	lastTime = curTime;
}

void FreeAndResetMemory()
{
	for (int i = 0; i <= cnt; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			if (newq[i][j] != NULL)
			{
				free(newq[i][j]);
				newq[i][j] = NULL;
			}
		}
		count[i] = 0;
	}
	e.x = player.x;
	e.y = player.y;
	s[cnt].x = enemysPos[cnt].x;
	s[cnt].y = enemysPos[cnt].y;

	Q[cnt] = NULL;

	memset(g[cnt], 0, sizeof(int)* MAPSIZE_Y* MAPSIZE_X);
	memset(pre[cnt], 0, sizeof(int)* MAPSIZE_Y* MAPSIZE_X);
	memset(visit[cnt], 0, sizeof(int)* MAPSIZE_Y* MAPSIZE_X);

}


void print_character(int z)
{
	int i, j, backtack;

	i = pre[z][e.y][e.x] / MAPSIZE_Y;
	j = pre[z][e.y][e.x] % MAPSIZE_Y;
	while (pre[z][i][j] != UNDEF)
	{
		backtack = pre[z][i][j];
		g[z][i][j] = 7;
		i = backtack / MAPSIZE_Y;
		j = backtack % MAPSIZE_Y;
	}

	g[z][e.y][e.x] = 7;
}

int empty_queue(int i)
{
	return Q[i] == NULL;
}


void enqueue(VERTEX v, QUEUE** Q, int i)
{
	f[i] = *Q;
	newq[i][count[i]] = (QUEUE*)calloc(2, sizeof(QUEUE));
	VERTEX temp;
	int key;
	newq[i][count[i]]->v= v;
	newq[i][count[i]]->next = NULL;
	if (f[i] == NULL)
	{
		*Q = newq[i][count[i]];
		if (count[i] != 0)
		{
			count[i] = 0;
		}
		return;
	}

	while (f[i]->next != NULL)
	{
		key = g[i][v.y][v.x];
		if (key < g[i][f[i]->v.y][f[i]->v.x])
		{
			temp = f[i]->v;
			f[i]->v = v;
			v = temp;
		}
		f[i] = f[i]->next;
	}
	newq[i][count[i]]->v = v;
	f[i]->next = newq[i][count[i]];
	count[i]++;
	if (count[i] == size[i])
	{
		// buffer 백업
		QUEUE* backupBuffer = newq[i];
		size[i] += 20;

		if (NULL == (newq[i] = (QUEUE**)realloc(newq[i], sizeof(*newq[i]) * size[i])))
		{
			// 종료 시
			free(backupBuffer);
			fprintf(stderr, "Memory allocation is failed");
			exit(1);
		}
	}
}

int calc_heuristic(VERTEX v, int c, int r, int* gx)
{
	int result;

	result = ((abs(e.y - c) + abs(e.x - r)) * 10);

	*gx = v.g;

	if (abs(v.y - c) == abs(v.x - r))
	{	// 대각선은 14를 더함
		*gx = *gx + 19;
	}
	else
	{	// 상하좌우는 10을 더함
		*gx = *gx + 10;
	}
	return result + *gx;
}



void add_openlist(VERTEX v, int visit[][MAPSIZE_X], int g[][MAPSIZE_X], int pre[][MAPSIZE_X], VERTEX* e, QUEUE** Q, int num)
{
	VERTEX temp;
	int i, j, w, gx;

	for (i = v.y - 1; i <= v.y + 1; i++)
	{
		if (i < 0 || i >= MAPSIZE_Y) continue;
		for (j = v.x - 1; j <= v.x + 1; j++)
		{
			if (j < 0 || j >= MAPSIZE_X || (i == v.y && j == v.x) ||
				visit[i][j] <= DONTMOVE) continue;

			w = calc_heuristic(v, i, j, &gx);

			if (w < g[i][j] || g[i][j] == INF)
			{
				g[i][j] = w;
				pre[i][j] = (v.y * MAPSIZE_Y) + v.x;
				if (e->y == i && e->x == j)
				{
					*Q = NULL;
					return;
				}
			}

			temp.y = i;
			temp.x = j;
			temp.g = gx;

			enqueue(temp, Q, num);

		}
	}
}


VERTEX dequeue(QUEUE** Q)
{
	QUEUE* ff = *Q;
	VERTEX v = { 0, 0, 0 };
	if (ff != NULL)
	{
		*Q = ff->next;
		v.y = ff->v.y;
		v.x = ff->v.x;
		v.g = ff->v.g;
		//free(ff);
		return v;
	}
	return v;
}

void astar(int pre[][MAPSIZE_X], VERTEX* s, int visit[][MAPSIZE_X], QUEUE** Q, int g[][MAPSIZE_X], VERTEX* e, int i)
{
	VERTEX v;
	pre[s->y][s->x] = UNDEF;
	s->g = 0;
	v = *s;	// 시작점 지정

	add_openlist(v, visit, g, pre, e, Q, i);

	while (!empty_queue(i))
	{
		visit[v.y][v.x] = CLOSED;
		v = dequeue(Q);

		add_openlist(v, visit, g, pre, e, Q, i);
	}
}
