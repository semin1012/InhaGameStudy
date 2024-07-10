#include <stdio.h>
#include <stdbool.h>
#include "stdafx.h"

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

