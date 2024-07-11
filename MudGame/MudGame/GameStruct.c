#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "Scene.h"
#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "Enemy.h"
#include "Astar.h"
#include "stdafx.h"

extern PLAYER player;
extern ENEMY enemy;
extern VERTEX s, e;	// start, end
extern DWORD lastTime;
extern bool gameOver;

void init(int *map[MAPSIZE_Y][MAPSIZE_X])
{
	system("mode con cols=120 lines=30 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	ScreenInit();


	player.x = 20;
	player.y = 20;
	player.coin = 0;

	if (!readStageFromFile(0)) {	// 읽기 실패하면 종료
		exit(0);
	}

	lastTime = clock();

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

	astar();
	print_character();
}


void update(bool* gameOver) {


	if (*gameOver == true)
	{
		if (GetAsyncKeyState('R') & 0x8000)	// ESC 눌렀을 때 바로 종료
			exit(0);
	}


	if (*gameOver == false) {
		if (isOverlapEnemy())
		{
			*gameOver = true;
			for (int i = 0; i < count; i++)
			{
				free(newq[i]);
			}
			free(newq);
			return;
		}

		UpdateFPS();
		moveEnemy();
		Sleep(100);
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)	// ESC 눌렀을 때 바로 종료
			exit(0);

		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			{
				if (map[player.y][player.x - 1] == 0)
				{
					player.x--;
				}
				else if (map[player.y][player.x - 1] == 2)
				{
					player.coin++;
					map[player.y][player.x - 1] = 0;
					player.x--;
				}
				else if (player.y == enemy.y && player.x - 1 == enemy.x)
					*gameOver = true;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			{
				if (map[player.y][player.x + 1] == 0)
				{
					player.x++;
				}
				else if (map[player.y][player.x + 1] == 2)
				{
					player.coin++;
					map[player.y][player.x + 1] = 0;
					player.x++;
				}
				else if (player.y == enemy.y && player.x + 1 == enemy.x)
					*gameOver = true;
			}
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			{
				if (map[player.y - 1][player.x] == 0)
				{
					player.y--;
				}
				else if (map[player.y - 1][player.x] == 2)
				{
					player.coin++;
					map[player.y - 1][player.x] = 0;
					player.y--;
				}
				else if (player.y - 1 == enemy.y && player.x == enemy.x)
					*gameOver = true;
			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			if (map[player.y + 1][player.x] == 0)
			{
				player.y++;
			}
			else if (map[player.y + 1][player.x] == 2)
			{
				player.coin++;
				map[player.y + 1][player.x] = 0;
				player.y++;
			}
			else if (player.y + 1 == enemy.y && player.x == enemy.x)
				*gameOver = true;
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
		ScreenPrint(player.x * 2 + MAP_VERTICAL_ALIGN, player.y, "㋡");
	}
	else 
	{
		i--;
		if (i == -2) 
		{
			i = 0;
			animDir = 0;
		}
		ScreenPrint(player.x * 2 + MAP_VERTICAL_ALIGN, player.y, "㋛");
	}
	


	setColor(RED);
	ScreenPrint(enemy.x * 2 + MAP_VERTICAL_ALIGN, enemy.y, "⛑");
	char coin_print[30] = "Coin: ";
	char coin_num[10];
	sprintf(coin_num, "%d", player.coin);
	strcat(coin_print, coin_num);

	setColor(SKYBLUE);
	ScreenPrint(20 + MAP_VERTICAL_ALIGN, 26, coin_print);
	ScreenFlipping();
}
