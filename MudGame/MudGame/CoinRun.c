#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "stdafx.h"
#pragma comment(lib, "winmm.lib")


PLAYER player;
ENEMY enemy = { 1, 1 };


// A* 알고리즘
#define UNDEF -1
#define CLOSED -3
#define DONTMOVE -1
#define INF 0


typedef struct vertex {
	int x;
	int y;
	int g;
} VERTEX;
typedef struct queue {
	VERTEX v;
	struct queue* next;
} QUEUE;

QUEUE* Q;
VERTEX s, e;	// start, end

int g[MAPSIZE_Y][MAPSIZE_X];
int visit[MAPSIZE_Y][MAPSIZE_X];
int pre[MAPSIZE_Y][MAPSIZE_X];



void astar(void);
void add_openlist(VERTEX);
int calc_heuristic(VERTEX v, int c, int r, int* gx);
void enqueue(VERTICAL);
VERTEX dequeue(void);
int empty_queue(void);
void print_weight(void);
void print_character(void);



void moveEnemy()
{

}


int dirX[8] = { 0, 0, 1, -1, -1, 1, 1, -1};
int dirY[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
int coinAllCnt = 0;

QUEUE* f = NULL;
QUEUE** newq;
int count = 0;
int size = 5;

static DWORD lastTime;   //마지막 시간(temp변수)

void UpdateFPS()
{
	static float timeElapsed = 0.0f;            //흐른 시간

	DWORD curTime = clock();      //현재 시간
	float timeDelta = (curTime - lastTime) ;        //timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.

	timeElapsed += timeDelta;

	if (timeElapsed >= 3000.0f)         //흐른 시간이 3초 이상이면 처리
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

		//timeElapsed = 0.0f;

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
		astar();
		print_character();
	}
	else
	{

	}


	lastTime = curTime;
}



int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	/*_CrtSetBreakAlloc(223);
	_CrtSetBreakAlloc(85);*/
	system("mode con cols=210 lines=60 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	bool gamestart = true;
	int i = 1;

	init();

	newq = (QUEUE**)calloc(size, sizeof(QUEUE*));

	/*     A* 알고리즘      */
	// 벽
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (map[i][j] == 1)
				visit[i][j] = -2;	// WALL = -2
		}
	}

	e.x = player.x;
	e.y = player.y;
	s.x = enemy.x;
	s.y = enemy.y;
	lastTime = clock();

	astar();
	print_character();


	int monsterMove = 0;

	while (1) {
		// 게임 시작 화면 
		if (gamestart == false) {
			game_start(i);
			i += 1;
			if (_kbhit())   // 아무키나 눌려지면 게임 스타트
			{
				gamestart = true;
			}
			Sleep(300);
		}

		// 플레이 화면
		if (gamestart == true) {
			//Q = NULL;
			monsterMove++;
			update();

			UpdateFPS();

			if (monsterMove % 3 == 0) {
				for (int i = 0; i < 8; i++)
				{
					g[enemy.y][enemy.x] = 8;
					int dir_x = enemy.x + dirX[i];
					int dir_y = enemy.y + dirY[i];

					if (g[dir_y][dir_x] == 7) {
						g[dir_y][dir_x] = 8;
						enemy.x = dir_x;
						enemy.y = dir_y;
						break;
					}
				}

				if (enemy.x == player.x && enemy.y == player.y)
					break;

				if (player.coin == coinAllCnt)
				{
					for (int i = 0; i < count; i++)
					{
						free(newq[i]);
					}
					free(newq);
					break;
				}
			}
			render();
			Sleep(150);
		}
	}


	_CrtDumpMemoryLeaks();
	//화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	//ScreenRelease(); 
	return 0;
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

VERTEX dequeue(void)
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
		newq = (QUEUE**)realloc(newq, sizeof(*newq)*size);
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



void add_openlist(VERTEX v)
{
	VERTEX temp;
	int cnt = 0;
	int i, j, w, gx;

	// 가까운 지점들 탐색한다
	for (i = v.y-1; i <= v.y+1; i++)
	{
		if (i < 0 || i >= MAPSIZE_Y) continue;
		for (j = v.x-1; j <= v.x+1; j++) 
		{
			if (j < 0 || j >= MAPSIZE_X || (i == v.y && j == v.x) ||
				visit[i][j] <= DONTMOVE) continue;

			w = calc_heuristic(v, i, j, &gx);

			if (w < g[i][j] || g[i][j] == INF)
			{
				g[i][j] = w;
				pre[i][j] = (v.y * MAPSIZE_Y) + v.x;
				if (e.y == i && e.x == j)
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

void astar(void)
{
	VERTEX v;
	pre[s.y][s.x] = UNDEF;	// 시작 지점은 루트가 없다
	s.g = 0;
	v = s;	// current 포인트를 시작점으로 만든다

	add_openlist(v);

	while (!empty_queue())
	{
		// 큐가 비지 않았다면 현재 점을 방문 목록에 넣는다
		visit[v.y][v.x] = CLOSED;
		v = dequeue();


		add_openlist(v);
	}
}