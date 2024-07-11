#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "CoinRun.h"
#include "stdafx.h"
#pragma comment(lib, "winmm.lib")



int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int i = 1;
	bool gameStart = false;

	newq = (QUEUE**)calloc(size, sizeof(QUEUE*));

	init();
	int monsterMove = 0;

	while (1) {
		// 게임 시작 화면 
		if (gameStart == false) {
			gameStartScene(&i, &gameStart);
		}

		// 플레이 화면
		if (gameStart == true) {
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
				{
					for (int i = 0; i < count; i++)
					{
						free(newq[i]);
					}
					free(newq);
					break;
				}

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
			Sleep(100);
		}
	}


	_CrtDumpMemoryLeaks();
	ScreenRelease(); 
	return 0;
}