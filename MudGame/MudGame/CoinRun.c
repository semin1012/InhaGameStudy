#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <crtdbg.h>
#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "CoinRun.h"
#include "stdafx.h"
#pragma comment(lib, "winmm.lib")


int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	int enemyMove = 0;
	bool gameStart = false;
	bool gameOver = false;
	newq = (QUEUE**)calloc(size, sizeof(QUEUE*));

	init();

	int idir = 0;

	while (1) {
		// 게임 시작 화면 
		if (gameStart == false) {
			gameStartScene(&gameStart);
			//printGameOver();
		}

		// 플레이 화면
		if (gameStart == true) 
		{			
			if (gameOver == false) 
			{
				update(&enemyMove);

				if (enemy.x == player.x && enemy.y == player.y)
				{
					for (int i = 0; i < count; i++)
					{
						free(newq[i]);
					}
					free(newq);

					gameOver = true;
				}

				if (player.coin == coinAllCnt)
				{
					for (int i = 0; i < count; i++)
					{
						free(newq[i]);
					}
					free(newq);

					// TODO: 다음 스테이지로 넘어가게 해야 됨
					break;
				}

				render();
			}

			else if (gameOver == true)
			{
				printGameOver();
			}
		}
	}


	_CrtDumpMemoryLeaks();
	ScreenRelease(); 
	return 0;
}