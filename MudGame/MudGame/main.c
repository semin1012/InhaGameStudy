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
				ScreenPrint(i*2, j, "□");
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
	ScreenPrint(player.x, player.y, "♀");
	ScreenFlipping();
}


void game_start(int i)
{
	ScreenClear();

	ScreenPrint(0, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠁⠀⠀⣴⣶⡄⠀⣶⣶⡄⠀⣴⣶⡄\n");
	ScreenPrint(0, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠀⠙⠋⠁⠀⠉⠋⠁⠀⠙⠋⠀\n");
	ScreenPrint(0, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");

	ScreenPrint(0, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣶⣶⡄⠀⣴⣶⡄\n");
	ScreenPrint(0, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠀⠉⠋⠁⠀⠙⠋⠀\n");
	ScreenPrint(0, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	ScreenPrint(0, 18, "     ○ ");
	ScreenPrint(i, 20, "    ​ ◝◜  ⠀  ⠀⠀◝◜         ◝◜  ⠀  ⠀⠀◝◜  ◝◜⠀◝◜                      ◝◜⠀◝◜    ◝◜   ◝◜  ⠀◝◜        ◝◜ ◝◜◝◜\n");
	ScreenPrint(i, 21, "⠀             ◝◜  ⠀◝◜⠀◝◜  ⠀  ⠀⠀⠀⠀⠀⠀⠀◝◜   ◝◜  ⠀◝◜◝◜⠀◝◜         ◝◜  ◝◜          ◝◜⠀◝◜        ◝◜ ◝◜⠀\n");
	ScreenPrint(0, 22, "_◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲__◢╲___◢╲◢╲_◢╲_◢╲_\n");
	ScreenPrint(0, 23, " ☁         ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁          ☁\n");

	ScreenFlipping();
}

void release() {
}

int main(void) {
	int nKey, nRemain;
	bool gamestart = false;

	ScreenInit();//버퍼를 2개 생성한다.
	init();
	int i = 1;

	while (1) {

		game_start(i);
		i += 2;

		if (gamestart == true) {
			update();
			render();
		}

		if (_kbhit()) { //키보드가 눌렸는지 체크 
			nKey = _getch(); //눌린값 대입
			if (nKey == 'q') //q를 눌렀다면 break
				break;
			else if (nKey == 224 || nKey == 0) {
				nKey = _getch();
				switch (nKey) {
				case 75: //왼쪽 방향키를 눌렀다면 
					player.x--;
					break;
				case 77:  //오른쪽 방향키를 눌렀다면
					player.x++;
					break;

				case 72:  //위쪽 방향키를 눌렀다면
					player.y--;
					break;

				case 80:  //아래쪽 방향키를 눌렀다면
					player.y++;
					break;
				}
			}
		}
		Sleep(300);
	}


	release();
	ScreenRelease(); //화면 버퍼 초기화 함수에서 생성한 두 개의 화면 버퍼를 모두 해제한다.
	return 0;
}