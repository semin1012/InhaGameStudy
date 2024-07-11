#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "consoleFunc.h"
#include "Scene.h"
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
				setColor(WHITE);
				ScreenPrint(i * 2, j, "■");
			}
			else if (map[j][i] == 0) {
				ScreenPrint(i * 2, j, " ");
			}
			else {
				setColor(YELLOW);
				ScreenPrint(i * 2, j, "⸰");
			}
		}
		printf("\n");
	}
}

int gameStartScene(int* i, bool* gameStart)
{
	game_start(*i);
	*i += 1;
	if (_kbhit())   // 아무키나 눌려지면 게임 스타트
	{
		*gameStart = true;
	}
	Sleep(300);
}

void game_start(int i)
{
	ScreenClear();

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

	ScreenPrint(35, 12, " CCC  OOO  III N   N    RRRR  U   U N   N ");
	ScreenPrint(35, 13, "C    O   O  I  NN  N    R   R U   U NN  N ");
	ScreenPrint(35, 14, "C    O   O  I  N N N    RRRR  U   U N N N ");
	ScreenPrint(35, 15, "C    O   O  I  N  NN    R R   U   U N  NN ");
	ScreenPrint(35, 16, " CCC  OOO  III N   N    R  RR  UUU  N   N ");

	ScreenPrint(44, 20, "Press Enter to Start");
	ScreenPrint(0, 18 + 4, "     ○ ");
	ScreenPrint(i, 20 + 4, "    ​ ◝◜  ⠀  ⠀⠀◝◜         ◝◜  ⠀  ⠀⠀◝◜  ◝◜⠀◝◜                      ◝◜⠀◝◜    ◝◜   ◝◜  ⠀◝◜        ◝◜ ◝◜◝◜\n");
	ScreenPrint(i, 21 + 4, "⠀             ◝◜  ⠀◝◜⠀◝◜  ⠀  ⠀⠀⠀⠀⠀⠀⠀◝◜   ◝◜  ⠀◝◜◝◜⠀◝◜         ◝◜  ◝◜          ◝◜⠀◝◜        ◝◜ ◝◜⠀\n");
	ScreenPrint(0, 22 + 4, "_◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲_\n");
	ScreenPrint(0, 23 + 4, " ☁         ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁\n");

	ScreenFlipping();
}