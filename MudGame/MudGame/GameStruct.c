#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
#include "Scene.h"
#include "ConsoleFunc.h"
#include "stdafx.h"

extern PLAYER player;
extern ENEMY enemy;


void init()
{
	system("mode con cols=120 lines=30 | title Coin Run"); // 콘솔창 크기 및 제목 설정

	ScreenInit();

	player.x = 5;
	player.y = 5;
	player.coin = 0;

	if (!readStageFromFile(0)) {	// 읽기 실패하면 종료
		exit(0);
	}
}


void update() {
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)	// ESC 눌렀을 때 바로 종료
		exit(0);

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
}

void render()
{
	ScreenClear();
	drawMap();
	setColor(GREEN);
	ScreenPrint(player.x * 2, player.y, "㋡");


	setColor(RED);
	ScreenPrint(enemy.x * 2, enemy.y, "⛑");
	char coin_print[30] = "Coin: ";
	char coin_num[10];
	sprintf(coin_num, "%d", player.coin);
	strcat(coin_print, coin_num);

	setColor(SKYBLUE);
	ScreenPrint(50, 29, coin_print);
	ScreenFlipping();
}
