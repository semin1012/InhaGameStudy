#include <stdio.h>
#include "stdafx.h"
#include "Enemy.h"

extern ENEMY enemy;
extern int dirX[];
extern int dirY[];
extern PLAYER player;
extern int enemySpeed;
extern int enemyNum;
extern ENEMY enemysPos[10];

extern int enemyFixedNum;
extern ENEMY enemysFixedPos[10];

void moveEnemy(bool init)
{
	static int enemyMove = 0;
	static int i = 0;
	static int idir = 0;
	enemyMove++;

	
	if (enemyMove % enemySpeed == 0) {
		for (int j = 0; j < enemyNum; j++)
		{
			for (int i = 0; i < 8; i++)
			{
				g[j][enemysPos[j].y][enemysPos[j].x] = 8;
				int dir_x = enemysPos[j].x + dirX[i];
				int dir_y = enemysPos[j].y + dirY[i];

				if (g[j][dir_y][dir_x] == 7) {
					g[j][dir_y][dir_x] = 8;
					enemysPos[j].x = dir_x;
					enemysPos[j].y = dir_y;
					break;
				}
			}
		}
	}

	if (enemyMove % 4 == 0)
	{
		if (idir == 0)
		{
			i++;
			for (int i = 0; i < enemyFixedNum; i++)
			{
				if (map[enemysFixedPos[i].x + 1][enemysFixedPos[i].y] != 1)
					enemysFixedPos[i].x += 1;
			}
			if (i == 2)
			{
				idir = -1;
			}
		}
		else
		{
			i--;
			for (int i = 0; i < enemyFixedNum; i++)
			{
				if (map[enemysFixedPos[i].x - 1][enemysFixedPos[i].y] != 1)
					enemysFixedPos[i].x -= 1;
			}
			if (i == -2)
			{
				idir = 0;
			}
		}
	}
}

bool isOverlapEnemy()
{
	for (int i = 0; i < enemyNum; i++)
	{
		if (enemysPos[i].x == player.x && enemysPos[i].y == player.y)
			return true;
	}
	for (int i = 0; i < enemyFixedNum; i++)
	{
		if (enemysFixedPos[i].x == player.x && enemysFixedPos[i].y == player.y)
			return true;
	}

	return false;
}