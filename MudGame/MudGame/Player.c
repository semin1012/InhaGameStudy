#include <stdio.h>
#include <stdbool.h>
#include "stdafx.h"

extern PLAYER player;
extern int map[MAPSIZE_Y][MAPSIZE_X];

bool canGo(int x, int y)
{
	if (map[y][x] == 0)
		return true;
	else if (map[y][x] == 2)
	{
		player.coin++;
		map[y][x] = 0;
		return true;
	}
	return false;
}

int countCointNuminMap()
{
	int coin_num = 0;
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (map[i][j] == 2)
			{
				coin_num++;
			}
		}
	}

	return coin_num;
}