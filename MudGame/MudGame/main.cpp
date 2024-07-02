#include <stdio.h>
#include <string.h>
#include <windows.h>

void gotoxy(int x, int y);
void game_start();

int main()
{
	game_start();
}

void game_start()
{
	//gotoxy(20, 10);
	//printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄");
	//gotoxy(20, 11);
	//printf("████▌▄▌▄▐▐▌█████");
	//gotoxy(20, 12);
	//printf("████▌▄▌▄▐▐▌▀████");
	//gotoxy(20, 13);
	//printf("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀");

	gotoxy(5, 20);
	printf("ට   ​  ⠀◝◜  ⠀  ⠀⠀◝◜");
	gotoxy(5, 21);
	printf("⠀◝◜  ⠀◝◜⠀◝◜  ⠀  ⠀⠀⠀⠀⠀⠀⠀◝◜");
	gotoxy(5, 22);
	printf("_◢╲___◢╲◢╲_◢╲_◢╲_");
	gotoxy(5, 23);
	printf("𓀚𓀛𓀜𓀝𓀞𓀟𓀠𓀡𓀢𓀣𓀤𓀥𓀦𓀧𓀨𓀩");

}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}