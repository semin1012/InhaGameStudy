#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "consoleFunc.h"
#include "Scene.h"
#include "Astar.h"
#include "stdafx.h"

extern int coinAllCnt;
extern DWORD lastTime;

bool readStageFromFile(int stage)
{
	FILE* ifp;
	char name[20];

	// txt 파일 이름 파싱
	strcpy(name, "../data/map_");
	char num[2];
	stage += 1;
	itoa(stage, num, 10);
	strcat(name, num);
	strcat(name, ".txt");
	// ex) name = "../data/map_1.txt"

	ifp = fopen(name, "rb");

	if (ifp == NULL) {
		printf("%s 파일 읽기를 실패하여 종료합니다.\n", name);
		return false;
	}
	else {
		for (int i = 0; i < MAPSIZE_Y; i++) {
			for (int j = 0; j < MAPSIZE_X; j++) {
				fscanf(ifp, "%d", &map[i][j]);
			}
		}

		fscanf(ifp, "%d", &coinAllCnt);

		fclose(ifp);
		return true;
	}
}

void drawMap()
{
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			if (map[j][i] == 1) {
				setColor(DARKGRAY);
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, "■");
			}
			else if (map[j][i] == 0) {
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, " ");
			}
			else {
				setColor(YELLOW);
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, "⸰");
			}
		}
		printf("\n");
	}
}


void gameStartScene(bool* gameStart)
{
	game_start();
	if (_kbhit())   // 아무키나 눌려지면 게임 스타트
	{
		for (int j = 0; j < count; j++)
		{
			free(newq[j]);
		}

		count = 0;

		e.x = player.x;
		e.y = player.y;
		s.x = enemy.x;
		s.y = enemy.y;

		Q = NULL;

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
		*gameStart = true;
	}
	Sleep(300);
}

void game_start()
{
	static int i = 0;
	i++;
	ScreenClear();

	setColor(YELLOW);

	if (i % 2 == 0) {
		ScreenPrint(44, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠁⠀⠀⣴⣶⡄⠀⣶⣶⡄⠀⣴⣶⡄\n");
		ScreenPrint(44, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠀⠙⠋⠁⠀⠉⠋⠁⠀⠙⠋⠀\n");
		ScreenPrint(44, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	}
	else {
		ScreenPrint(44, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠀⣶⣶⡄⠀⣴⣶⡄\n");
		ScreenPrint(44, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠀⠉⠋⠁⠀⠙⠋⠀\n");
		ScreenPrint(44, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		ScreenPrint(44, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	}
	setColor(WHITE);

	ScreenPrint(35, 12, " CCC  OOO  III N   N    RRRR  U   U N   N ");
	ScreenPrint(35, 13, "C    O   O  I  NN  N    R   R U   U NN  N ");
	ScreenPrint(35, 14, "C    O   O  I  N N N    RRRR  U   U N N N ");
	ScreenPrint(35, 15, "C    O   O  I  N  NN    R R   U   U N  NN ");
	ScreenPrint(35, 16, " CCC  OOO  III N   N    R  RR  UUU  N   N ");

	setColor(RED);
	ScreenPrint(44, 20, "Press Enter to Start");

	setColor(YELLOW);
	ScreenPrint(0, 18 + 4, "     ● ");
	setColor(BLUE);
	ScreenPrint(i, 20 + 4, "    ​ ◝◜  ⠀  ⠀⠀◝◜         ◝◜  ⠀  ⠀⠀◝◜  ◝◜⠀◝◜                      ◝◜⠀◝◜    ◝◜   ◝◜  ⠀◝◜        ◝◜ ◝◜◝◜\n");
	ScreenPrint(i, 21 + 4, "⠀             ◝◜  ⠀◝◜⠀◝◜  ⠀  ⠀⠀⠀⠀⠀⠀⠀◝◜   ◝◜  ⠀◝◜◝◜⠀◝◜         ◝◜  ◝◜          ◝◜⠀◝◜        ◝◜ ◝◜⠀\n");

	setColor(DARKGREEN);
	ScreenPrint(0, 22 + 4, "_◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲_\n");
	ScreenPrint(0, 23 + 4, " ☁         ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁\n");

	ScreenFlipping();
}

void printGameOver()
{
	static int idir = 0;
	static int i = 0;
	ScreenClear();

	setColor(WHITE);
	ScreenPrint(10, 1 + 17 + i, ":'######::::::'###::::'##::::'##:'########:::::'#######::'##::::'##:'########:'########::'####:\n");
	ScreenPrint(10, 2 + 17 + i, "'##... ##::::'## ##::: ###::'###: ##.....:::::'##.... ##: ##:::: ##: ##.....:: ##.... ##: ####:\n");
	ScreenPrint(10, 3 + 17 + i, " ##:::..::::'##:. ##:: ####'####: ##:::::::::: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##: ####:\n");
	ScreenPrint(10, 4 + 17 + i, " ##::'####:'##:::. ##: ## ### ##: ######:::::: ##:::: ##: ##:::: ##: ######::: ########::: ##::\n");
	ScreenPrint(10, 5 + 17 + i, " ##::: ##:: #########: ##. #: ##: ##...::::::: ##:::: ##:. ##:: ##:: ##...:::: ##.. ##::::..:::\n");
	ScreenPrint(10, 6 + 17 + i, " ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::::: ##:::: ##::. ## ##::: ##::::::: ##::. ##::'####:\n");
	ScreenPrint(10, 7 + 17 + i, ". ######::: ##:::: ##: ##:::: ##: ########::::. #######::::. ###:::: ########: ##:::. ##: ####:\n");
	ScreenPrint(10, 8 + 17 + i, ":......::::..:::::..::..:::::..::........::::::.......::::::...:::::........::..:::::..::....::\n");

	setColor(WHITE);
	ScreenPrint(13 , 12 - 11, "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
	ScreenPrint(13 , 13 - 11, "|　도망 실패!　　　　　　　　　 　　 [－][口][×]|\n");
	ScreenPrint(13 , 14 - 11, "|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
	ScreenPrint(13 , 15 - 11, "|　경찰에게 잡혔습니다!                       　 |\n");
	ScreenPrint(13 , 16 - 11, "|　다시 플레이를 원하면 r 을 누르세요 　　　　　 |\n");
	ScreenPrint(13 , 17 - 11, "|　　　＿＿＿＿＿＿　　　　 　　＿＿＿＿＿＿　 　|\n");
	ScreenPrint(13 , 18 - 11, "| 　　｜예　　　　 |　　　 　　|예　 　　   |　  |\n");
	ScreenPrint(13 , 19 - 11, "|　　　￣￣￣￣￣￣　　　　　 　￣￣￣￣￣￣　　 |\n");
	ScreenPrint(13 , 20 - 11, "￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");

	setColor(DARKGRAY);
	ScreenPrint(80, 2 + 7, "┏┯┯┯┯┯┯┯┯┯┓\n");
	ScreenPrint(80, 3 + 7, "┃││∧ ∧││┃ 살려줘!!\n");
	ScreenPrint(80, 4 + 7, "┃│(≧Д≦)┃\n");
	ScreenPrint(80, 5 + 7, "┃│ф  ф││┃\n");
	ScreenPrint(80, 6 + 7, "┗┷┷┷┷┷┷┷┷┷┛\n");

	if (idir == 0)
	{
		i++;
		if (i == 2)
			idir = -1;
	}
	if (idir == -1)
	{
		i--;
		if (i == -2)
			idir = 0;
	}

	ScreenFlipping();
	Sleep(150);
}
