#include <stdio.h>
#include <stdbool.h>
#include "stdafx.h"
#include "Enemy.h"

extern ENEMY enemy;
extern int dirX[];
extern int dirY[];
extern PLAYER player;
extern int enemySpeed;
extern int enemyNum;
extern ENEMY enemysPos[10];

void moveEnemy()
{
	static int enemyMove = 0;
	static int i = 0;
	static int idir = 0;
	enemyMove++;

	if (enemyMove % enemySpeed == 0) {
		for (int i = 0; i < 8; i++)
		{
			g[enemy.y][enemy.x] = 8;
			int dir_x = enemy.x + dirX[i];
			int dir_y = enemy.y + dirY[i];

			if (g[dir_y][dir_x] == 7) {
				g[dir_y][dir_x] = 8;
				enemy.x = dir_x;
				enemy.y = dir_y;
				break;
			}
		}
	}

	if (enemyMove % 4 == 0)
	{
		if (idir == 0)
		{
			i++;
			for (int i = 0; i < enemyNum; i++)
			{
				enemysPos[i].x += 1;
			}
			if (i == 2)
			{
				idir = -1;
			}
		}
		else 
		{
			i--;
			for (int i = 0; i < enemyNum; i++)
			{
				enemysPos[i].x -= 1;
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
	if (enemy.x == player.x && enemy.y == player.y) {
		return true;
	}
	else return false;
}