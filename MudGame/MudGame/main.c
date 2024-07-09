#include <stdio.h>
#include<Windows.h>
#include <string.h>
#include <stdbool.h>
#include "Screen.h"


typedef struct _PLAYER
{
	int x, y; // 출력기준좌표
} PLAYER;

PLAYER player;

void init() {
	player.x = 20;
	player.y = 10;
}

void drawMap() {
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			if (map[j][i] == 1)
				ScreenPrint(i*2, j, "■");
			else ScreenPrint(i*2, j, " ");
		}
		printf("\n");
	}
}

void update() {

}

void render()
{
	ScreenClear();
	drawMap();
	ScreenPrint(player.x, player.y, "●");
	ScreenFlipping();
}


/*
 _____   ___  ___  ___ _____   _____  _____   ___  ______  _____ 
|  __ \ / _ \ |  \/  ||  ___| /  ___||_   _| / _ \ | ___ \|_   _|
| |  \// /_\ \| .  . || |__   \ `--.   | |  / /_\ \| |_/ /  | |  
| | __ |  _  || |\/| ||  __|   `--. \  | |  |  _  ||    /   | |  
| |_\ \| | | || |  | || |___  /\__/ /  | |  | | | || |\ \   | |  
 \____/\_| |_/\_|  |_/\____/  \____/   \_/  \_| |_/\_| \_|  \_/  
 */

/*
  __   _   _  _  _   ___  _ _  _  _ 
 / _| / \\ | || \\| | | o \\| | || \\| |
( (_ ( o )| || \\\\ | |   /| U || \\\\ |
 \\__| \\_/ |_||_|\\_| |_|\\\\|___||_|\\_|
                                    
*/

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

	ScreenPrint(35, 13, " CCC  OOO  III N   N    RRRR  U   U N   N ");
	ScreenPrint(35, 14, "C    O   O  I  NN  N    R   R U   U NN  N ");
	ScreenPrint(35, 15, "C    O   O  I  N N N    RRRR  U   U N N N ");
	ScreenPrint(35, 16, "C    O   O  I  N  NN    R R   U   U N  NN ");
	ScreenPrint(35, 17, " CCC  OOO  III N   N    R  RR  UUU  N   N ");

	ScreenPrint(44, 20, "Press Enter to Start");
	ScreenPrint(0, 18 + 4, "     ○ ");
	ScreenPrint(i, 20 + 4, "    ​ ◝◜  ⠀  ⠀⠀◝◜         ◝◜  ⠀  ⠀⠀◝◜  ◝◜⠀◝◜                      ◝◜⠀◝◜    ◝◜   ◝◜  ⠀◝◜        ◝◜ ◝◜◝◜\n");
	ScreenPrint(i, 21 + 4, "⠀             ◝◜  ⠀◝◜⠀◝◜  ⠀  ⠀⠀⠀⠀⠀⠀⠀◝◜   ◝◜  ⠀◝◜◝◜⠀◝◜         ◝◜  ◝◜          ◝◜⠀◝◜        ◝◜ ◝◜⠀\n");
	ScreenPrint(0, 22 + 4, "_◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲_\n");
	ScreenPrint(0, 23 + 4, " ☁         ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁\n");

	ScreenFlipping();
}

bool canGo(int x, int y)
{
	if (map[y][x] == 0)
		return true;
	return false;
}

int main(void) {
	int nRemain;
	bool gamestart = false;

	ScreenInit();//버퍼를 2개 생성한다.
	init();
	int i = 1;

	while (1) {

		if (gamestart == false) {
			game_start(i);
			i += 1;
			if (_kbhit())   // 아무키나 눌려지면 멈춥니다
			{
				gamestart = true;
			}
			Sleep(300);
		}

		if (gamestart == true) {
			update();
			render();

			if (GetAsyncKeyState('Q') & 0x8000)	// Q 눌렀을 때
				break;

			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (canGo(player.x - 1, player.y))
					player.x--;
			}
			
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
				if (canGo(player.x + 1, player.y))
					player.x++;
			}
			
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				if (canGo(player.x, player.y - 1))
					player.y--;
			}
			
			if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				if (canGo(player.x, player.y + 1))
					player.y++;
			}
			Sleep(10);
		}
	}

	ScreenRelease(); //화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	return 0;
}