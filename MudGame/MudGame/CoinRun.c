#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include <crtdbg.h>
#include "ConsoleFunc.h"
#include "Scene.h"
#include "GameStruct.h"
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
		if (gameStart == true) 
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
					printGameClearAtStage(&gameStart, &gameClear, &stage, stage + 1);
				}
			}

			else if (gameOver == true)
			{
				printGameOver(&gameStart, &gameOver);
			}
		}
	}


	_CrtDumpMemoryLeaks();
	ScreenRelease(); 
	return 0;
}