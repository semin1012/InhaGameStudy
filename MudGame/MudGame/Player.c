#include <stdio.h>
#include "stdafx.h"
#include "Sound.h"
#include "Astar.h"

extern PLAYER player;
extern int map[MAPSIZE_Y][MAPSIZE_X];
extern ENEMY enemy;

extern VERTEX s, e;	// start, end
extern int count;

extern QUEUE* Q;
extern QUEUE** newq[10];

void movePlayer(int x, int y, bool* gameOver)
{
	if (map[y][x] == 0)
	{
		player.x = x;
		player.y = y;
	}
	else if (map[y][x] == 2)
	{
		playingGetCoinSound();
		player.coin++;
		map[y][x] = 0;
		player.x = x;
		player.y = y;
	}
	if (y == enemy.y && x == enemy.x)
		*gameOver = true;
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


void setDeath(bool* gameOver)
{
	pauseBgm(&playingBgm, dwID);
	playingDeathSound();

	*gameOver = true;
	for (int i = 0; i < count; i++)
	{
		free(newq[0][i]);
	}

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

	count = 0;
}