#include <stdio.h>
#include "Scene.h"
#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "Enemy.h"
#include "Sound.h"
#include "Player.h"
#include "Astar.h"
#include "stdafx.h"

extern PLAYER player;
extern ENEMY enemy;
extern DWORD lastTime;
extern bool gameOver;
extern int stage;
extern int coinAllCnt;
extern int enemyNum;
extern ENEMY enemysPos[10];

extern int enemyFixedNum;
extern ENEMY enemysFixedPos[10];

extern QUEUE* Q[10];
extern VERTEX s[10];
extern VERTEX e;	// start, end

extern QUEUE* f[10];
extern QUEUE** newq[10];
extern int count[10];
extern int size[10];

void init()
{
	system("mode con cols=120 lines=30 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	ScreenInit();

	player.coin = 0;

	if (!readStageFromFile(stage)) {	// 읽기 실패하면 종료
		exit(0);
	}
	if (!readMaxCoinData()) {	// 읽기 실패하면 종료
		exit(0);
	}

	lastTime = clock();

	/*     A* 알고리즘      */
	// 벽
	//for (int i = 0; i < MAPSIZE_Y; i++)
	//{
	//	for (int j = 0; j < MAPSIZE_X; j++)
	//	{
	//		if (map[i][j] == 1)
	//			visit[0][i][j] = -2;	// WALL = -2
	//	}
	//}

	//e.x = player.x;
	//e.y = player.y;
	//s.x = enemy.x;
	//s.y = enemy.y;


	//count = 0;

	//Q = NULL;

	//memset(g, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
	//memset(pre, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
	//memset(visit, 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);

	//astar(pre, &s, visit, &Q, g, &e, 0);
	//print_character();


	for (int i = 0; i < 1; i++)
	{
		e.x = player.x;
		e.y = player.y;
		s[i].x = enemysPos[i].x;
		s[i].y = enemysPos[i].y;

		Q[i] = NULL;

		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			for (int z = 0; z < MAPSIZE_X; z++)
			{
				if (map[j][z] == 1)
					visit[i][j][z] = -2;	// WALL = -2
			}
		}
		astar(pre[i], &s[i], visit[i], &Q[i], g[i], &e, 0);
		print_character(i);
	}

	playingIntroBgm();
}


// TODO: 저장
void saveData()
{

}


void inputDebugKey()
{
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 0;
			}
		}
	}
}

void update(bool* gameOver) {

	if (*gameOver == false ) {
		// 몬스터와 닿았다면 게임오버
		if (isOverlapEnemy())
		{
			setDeath(gameOver);
			return;
		}

		UpdateFPS();
		moveEnemy(false);
		Sleep(50);

		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)	// ESC 눌렀을 때 바로 종료
			exit(0);


		// 디버깅 키
		if (GetAsyncKeyState('D') & 0x8000) {
			inputDebugKey();
		}

		if (GetAsyncKeyState('S') & 0x8000) {
			// TODO: 저장
			saveData();
		}

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			movePlayer(player.x - 1, player.y, gameOver);
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			movePlayer(player.x + 1, player.y, gameOver);
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			movePlayer(player.x, player.y-1, gameOver);
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			movePlayer(player.x, player.y+1, gameOver);
		}
	}
}

void render()
{
	static int i = 0;
	static int animDir = 0;
	ScreenClear();
	drawMap();

	setColor(YELLOW);
	if (animDir == 0)
	{
		i++;
		if (i == 2)
		{
			i = 0;
			animDir = -1;
		}
		ScreenPrint(player.x * 2 + MAP_VERTICAL_ALIGN, player.y, "●");
	}
	else
	{
		i--;
		if (i == -2)
		{
			i = 0;
			animDir = 0;
		}
		ScreenPrint(player.x * 2 + MAP_VERTICAL_ALIGN, player.y, "●");
	}



	setColor(RED);
	//ScreenPrint(enemy.x * 2 + MAP_VERTICAL_ALIGN, enemy.y, "※");

	for (int i = 0; i < enemyNum; i++)
	{
		ScreenPrint(enemysPos[i].x * 2 + MAP_VERTICAL_ALIGN, enemysPos[i].y, "※");
	}

	for (int i = 0; i < enemyFixedNum; i++)
	{
		ScreenPrint(enemysFixedPos[i].x * 2 + MAP_VERTICAL_ALIGN, enemysFixedPos[i].y, "※");
	}

	char coin_print[30] = "Coin: ";
	char coin_num[10];
	sprintf(coin_num, "%d", player.coin);
	strcat(coin_print, coin_num);

	setColor(SKYBLUE);
	ScreenPrint(20 + MAP_VERTICAL_ALIGN, 26, coin_print);
	ScreenFlipping();
}
