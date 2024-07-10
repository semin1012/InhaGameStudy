#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>
#include "ConsoleFunc.h"
#include "GameStruct.h"
#include "stdafx.h"


PLAYER player;
ENEMY enemy = { 1, 1 };



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


int main(void) {
	bool gamestart = false;

	ScreenInit();//버퍼를 2개 생성한다.
	init();
	int i = 1;

	while (1) {

		if (gamestart == false) {
			game_start(i);
			i += 1;
			if (_kbhit())   // 아무키나 눌려지면 게임 스타트
			{
				gamestart = true;
			}
			Sleep(300);
		}

		if (gamestart == true) {
			update();
			render();
			Sleep(15);
		}
	}

	ScreenRelease(); //화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	return 0;
}