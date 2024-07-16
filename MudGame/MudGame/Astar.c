#include <stdio.h>
#include <stdlib.h>

#include "stdafx.h"
#include "Astar.h"

QUEUE* Q;
VERTEX s, e;	// start, end

QUEUE* f = NULL;
QUEUE** newq;
int count = 0;
int size = 5;

// =========================================


QUEUE* Q2;
VERTEX s2, e2;	// start, end

QUEUE* f2 = NULL;
QUEUE** newq2;
int count2 = 0;
int size2 = 5;

extern PLAYER player;
extern ENEMY enemy;

void UpdateFPS()
{
	static float timeElapsed = 5000.0f;            //흐른 시간

	DWORD curTime = clock();      //현재 시간
	float timeDelta = (curTime - lastTime);        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta;

	if (timeElapsed >= 1000.0f)         //흐른 시간이 3초 이상이면 처리
	{
		for (int i = 0; i < count; i++)
		{
			free(newq[i]);
		}

		count = 0;

		e.x = player.x;
		e.y = player.y;
		s.x = enemy.x;
		s.y = enemy.y;

		Q = NULL;

		memset(g, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		memset(pre, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		memset(visit, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);

		for (int i = 0; i < MAPSIZE_Y; i++)
		{
			for (int j = 0; j < MAPSIZE_X; j++)
			{
				if (map[i][j] == 1)
					visit[i][j] = -2;	// WALL = -2
			}
		}
		astar(pre, &s, visit, Q, g, &e);
		print_character();

		timeElapsed = 0.0f;
	}
	else if (timeElapsed >= 2000.0f)
	{
		//for (int i = 0; i < count2; i++)
		//{
		//	free(newq2[i]);
		//}

		//count2 = 0;

		//// TODO, 적 추가
		//e.x = player.x;
		//e.y = player.y;
		//s.x = enemy.x;
		//s.y = enemy.y;

		//Q2 = NULL;

		//memset(g2, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		//memset(pre2, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		//memset(visit2, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);

		//for (int i = 0; i < MAPSIZE_Y; i++)
		//{
		//	for (int j = 0; j < MAPSIZE_X; j++)
		//	{
		//		if (map[i][j] == 1)
		//			visit2[i][j] = -2;	// WALL = -2
		//	}
		//}
		//astar(&pre, &s, &visit, Q, &g, &e);
		//print_character();

		//timeElapsed = 0.0f;
	}

	lastTime = curTime;
}


void print_character(void)
{
	int i, j, backtack;

	i = pre[e.y][e.x] / MAPSIZE_Y;
	j = pre[e.y][e.x] % MAPSIZE_Y;
	while (pre[i][j] != UNDEF)
	{
		backtack = pre[i][j];
		g[i][j] = 7;
		i = backtack / MAPSIZE_Y;
		j = backtack % MAPSIZE_Y;
	}

	g[e.y][e.x] = 7;
}

int empty_queue(void)
{
	return Q == NULL;
}


void enqueue(VERTEX v)
{
	f = Q;
	newq[count] = (QUEUE*)calloc(2, sizeof(QUEUE));
	VERTEX temp;
	int cnt = 0;
	int key;
	newq[count]->next = NULL;
	newq[count]->v = v;
	if (f == NULL)
	{
		Q = newq[count];
		return;
	}

	while (f->next != NULL)
	{
		key = g[v.y][v.x];
		if (key < g[f->v.y][f->v.x])
		{
			temp = f->v;
			f->v = v;
			v = temp;
		}
		f = f->next;
	}
	newq[count]->v = v;
	f->next = newq[count];
	count++;
	if (count == size)
	{
		size += 5;
		newq = (QUEUE**)realloc(newq, sizeof(*newq) * size);
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



void add_openlist(VERTEX *v, int visit[][MAPSIZE_X], int g[][MAPSIZE_X], int pre[][MAPSIZE_X], VERTEX* e, QUEUE* Q)
{
	VERTEX temp;
	int cnt = 0;
	int i, j, w, gx;

	// 가까운 지점들 탐색한다
	for (i = v->y - 1; i <= v->y + 1; i++)
	{
		if (i < 0 || i >= MAPSIZE_Y) continue;
		for (j = v->x - 1; j <= v->x + 1; j++)
		{
			if (j < 0 || j >= MAPSIZE_X || (i == v->y && j == v->x) ||
				visit[i][j] <= DONTMOVE) continue;

			w = calc_heuristic(*v, i, j, &gx);

			if (w < g[i][j] || g[i][j] == INF)
			{
				g[i][j] = w;
				pre[i][j] = (v->y * MAPSIZE_Y) + v->x;
				if (e->y == i && e->x == j)
				{
					Q = NULL;
					return;
				}
			}

			temp.y = i;
			temp.x = j;
			temp.g = gx;

			enqueue(temp);

		}
	}
	//printf("eee (%d, %d) 방문\n", enemy.x, enemy.y);
}


VERTEX dequeue(QUEUE* Q)
{
	QUEUE* ff = Q;
	VERTEX v = { 0, 0, 0 };
	if (ff != NULL)
	{
		Q = ff->next;
		v.y = ff->v.y;
		v.x = ff->v.x;
		v.g = ff->v.g;
		//free(ff);
		return v;
	}
	return v;
}

void astar(int pre[][MAPSIZE_X], VERTEX* s, int visit[][MAPSIZE_X], QUEUE* Q, int g[][MAPSIZE_X], VERTEX* e)
{
	VERTEX v;
	pre[s->y][s->x] = UNDEF;	// 시작 지점은 루트가 없다
	//(*(pre+ 1) + 1) = UNDEF;
	s->g = 0;
	v = *s;	// current 포인트를 시작점으로 만든다

	add_openlist(&v, visit, g, pre, e, Q);

	while (!empty_queue())
	{
		// 큐가 비지 않았다면 현재 점을 방문 목록에 넣는다
		visit[v.y][v.x] = CLOSED;
		v = dequeue(Q);

		add_openlist(&v, visit, g, pre, e, Q);
	}
}