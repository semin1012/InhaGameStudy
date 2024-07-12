#include <stdio.h>
#include <string.h>
#include <time.h>
#include <crtdbg.h>
#include "ConsoleFunc.h"
#include "Scene.h"
#include "GameStruct.h"
#include "CoinRun.h"
#include "stdafx.h"

extern bool gameOver;



int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	bool gameStart = false;
	bool gameOver = false;
	bool gameClear = false;
	newq = (QUEUE**)calloc(size, sizeof(QUEUE*));

	init();

	while (1) {
		// 게임 시작 화면 
		if (gameStart == false) {
			//printGameClearAtStage(&gameStart, &gameOver, 0);
			gameStartScene(&gameStart);
		}

		// 플레이 화면
		else if (gameStart == true) 
		{			
			if (gameOver == false) 
			{
				if (gameClear == false)
				{
					update(&gameOver);		// gameOver 여부에 따라 수행 동작이 다름
					render();
				}
				if (countCointNuminMap() == 0)
				{
					gameClear = true;
					if (stage == 2)
					{
						printGameAllStageClear(&gameStart, &gameClear, &stage);
					}
					else 
						printGameClearAtStage(&gameStart, &gameClear, &stage, stage + 1);
				}
			}

			else if (gameOver == true)
			{
				printGameOver(&gameStart, &gameOver, stage);
			}
		}
	}


	_CrtDumpMemoryLeaks();
	ScreenRelease(); 
	return 0;
}