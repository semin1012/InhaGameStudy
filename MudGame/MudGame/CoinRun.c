#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "stdafx.h"


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



void moveEnemy()
{

}



int main(void) {

	system("mode con cols=210 lines=60 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	bool gamestart = true;
	int i = 1;

	init();


	/*     A* 알고리즘      */
	// 시작점 (출발지)
	s.x = enemy.x;
	s.y = enemy.y;

	// 목적지 (도착지)
	e.x = player.x;	
	e.y = player.y;


	// 벽
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if ( map[i][j] == 1)
				visit[i][j] = -2;	// WALL = -2
		}
	}


	astar();
	//print_weight();

	//while (1) {
	//	// 게임 시작 화면 
	//	if (gamestart == false) {
	//		game_start(i);
	//		i += 1;
	//		if (_kbhit())   // 아무키나 눌려지면 게임 스타트
	//		{
	//			gamestart = true;
	//		}
	//		Sleep(300);
	//	}

	//	// 플레이 화면
	//	if (gamestart == true) {
	//		update();
	//		render();
	//		Sleep(15);
	//	}
	//}

	//화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	//ScreenRelease(); 
	return 0;
}


void print_weight(void)
{
	int i, j;
	for (i = 0; i < MAPSIZE_Y- 10; i++)
	{
		for (j = 0; j < MAPSIZE_X - 30; j++)
		{
			if (i == e.y && j == e.x)
			{
				printf("!");
			}
			printf("%4d", g[i][j]);
		}
		printf("\n");
	}
}


int empty_queue(void)
{
	return Q == NULL;
}

VERTEX dequeue(void)
{
	QUEUE* f = Q;
	VERTEX v = { 0, 0, 0 };
	if (f != NULL)
	{
		Q = f->next;
		v.y = f->v.y;
		v.x = f->v.x;
		v.g = f->v.g;
		free(f);
		return v;
	}
	return v;
}

void enqueue(VERTEX v)
{
	QUEUE* f = Q;
	QUEUE* newq = (QUEUE*)malloc(sizeof(QUEUE));
	VERTEX temp;
	int cnt = 0;
	int key;
	newq->next = NULL;
	newq->v = v;
	if (f == NULL)
	{
		Q = newq;
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
	newq->v = v;
	f->next = newq;
}

int calc_heuristic(VERTEX v, int c, int r, int* gx)
{
	int result;

	result = ((abs(e.y - c) + abs(e.x - r)) * 10);

	*gx = v.g;

	if (abs(v.y - c) == abs(v.x - r))
	{	// 대각선은 14를 더함
		*gx = *gx + 14;
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
				if (e.y == i && e.y == j)
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
}

void astar(void)
{
	VERTEX v;
	g[s.y][s.x] = 0;
	pre[s.y][s.x] = UNDEF;	// 시작 지점은 루트가 없다
	s.g = 0;
	v = s;	// current 포인트를 시작점으로 만든다

	add_openlist(v);

	while (!empty_queue())
	{
		// 큐가 비지 않았다면 현재 점을 방문 목록에 넣는다
		visit[v.y][v.x] = CLOSED;
		//printf("(%d, %d) 방문\n", v.x +1, v.y + 1);
		v = dequeue();


		add_openlist(v);
		enemy.x = v.x;
		enemy.y = v.y;
		printf("(%d, %d) 방문\n", enemy.x, enemy.y);
		Sleep(100);
	}

	enemy.x = player.x;
	enemy.y = player.y;
	printf("(%d, %d) 방문\n", enemy.x, enemy.y);
	printf("최종: (%d, %d)\n", enemy.x, enemy.y);

}