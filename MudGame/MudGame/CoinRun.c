#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <crtdbg.h>
#include "ConsoleFunc.h"
#include "CoinRun.h"
#include "stdafx.h"
#pragma comment(lib, "winmm.lib")

extern bool gameOver;

void replay(bool* gameOver)
{
	gameOver = false;
}

int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	bool gameStart = false;
	bool gameOver = false;
	newq = (QUEUE**)calloc(size, sizeof(QUEUE*));

	init();

	while (1) {
		// 게임 시작 화면 
		if (gameStart == false) {
			gameStartScene(&gameStart);
		}

		// 플레이 화면
		if (gameStart == true) 
		{			
			if (gameOver == false) 
			{
				update(&gameOver);		// gameOver 여부에 따라 수행 동작이 다름

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
				update(&gameOver);
				//replay(&gameOver);
			}
		}
	}


	_CrtDumpMemoryLeaks();
	ScreenRelease(); 
	return 0;
}