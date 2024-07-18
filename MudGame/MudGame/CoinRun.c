#include <stdio.h>
#include <string.h>
#include <time.h>
#include <crtdbg.h>
#include "ConsoleFunc.h"
#include "Scene.h"
#include "GameStruct.h"
#include "CoinRun.h"
#include "stdafx.h"
#include "Player.h"

extern bool gameOver;

#define MAX_ENEMY_NUM 5

int main(void) 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);

	bool gameStart = false;
	bool gameOver = false;
	bool gameClear = false;
	bool gameClose = false;

	for (int i = 0; i < MAX_ENEMY_NUM; i++) 
	{
		newq[i] = (QUEUE**)calloc(size[i], sizeof(QUEUE*));
	}
	init();

	bool bScriptScene = false;

	while (1) {
		if (gameClose == true)
		{
			// TODO
			// closeGame();
		}

		// 게임 시작 화면 
		if (gameStart == false) 
		{
			if (bScriptScene == false )
				gameStartScene(&gameStart, &bScriptScene);
			// TODO
			else scriptScene(&gameStart, &bScriptScene);
		}

		// 플레이 화면
		else if (gameStart == true) 
		{			
			if (gameClose == true)
			{
				break;
			}
			if (gameOver == false) 
			{
				if (gameClear == false)
				{
					update(&gameOver, &gameClose);		// gameOver 여부에 따라 수행 동작이 다름
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

	ScreenRelease();
	printf(" > 게임을 종료합니다.\n\n\n");
	for (int i = 0; i <= enemyNum; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			if (newq[i][j] != NULL)
			{
				free(newq[i][j]);
				newq[i][j] = NULL;
			}
		}
		count[i] = 0;
	}
	_CrtDumpMemoryLeaks();
	return 0;
}