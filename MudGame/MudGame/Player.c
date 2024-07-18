#include <stdio.h>
#include "stdafx.h"
#include "Sound.h"

extern PLAYER player;
extern int map[MAPSIZE_Y][MAPSIZE_X];
extern ENEMY enemy;

//extern VERTEX s[10], e;	// start, end
//extern int count[10];
//
//extern QUEUE* Q[10];
//extern QUEUE** newq[10];

extern VERTEX enemysPos[10];


extern QUEUE* Q[10];
extern VERTEX s[10];
extern VERTEX e;	// start, end

extern QUEUE* f[10];
extern QUEUE** newq[10];
extern int count[10];
extern int size[10];
extern int enemyNum;
extern VERTEX enemysPos[10];

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

	//for (int i = 0; i < enemyNum; i++)
	//{
	//	if (y == enemysPos[i].y && x == enemysPos[i].x)
	//	{
	//		*gameOver = true;
	//	}
	//}
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

	for (int i = 0; i < enemyNum; i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			if (newq[i][j] != NULL)
			{
				free(newq[i][j]);
				newq[i][j] = NULL;
			}
			free(newq[i][j]);
		}

		count[i] = 0;

		e.x = player.x;
		e.y = player.y;
		s[i].x = enemysPos[i].x;
		s[i].y = enemysPos[i].y;

		Q[i] = NULL;

		memset(g[i], 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		memset(pre[i], 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);
		memset(visit[i], 0, sizeof(int) * MAPSIZE_Y * MAPSIZE_X);

		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			for (int z = 0; z < MAPSIZE_X; z++)
			{
				if (map[j][z] == 1)
					visit[i][j][z] = -2;	// WALL = -2
			}
		}
	}
}