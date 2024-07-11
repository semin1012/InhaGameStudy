#include <stdio.h>
#include "stdafx.h"
#include "Enemy.h"

extern ENEMY enemy;
extern int dirX[];
extern int dirY[];

void moveEnemy(int* enemyMove)
{
	(*enemyMove)++;

	if (*enemyMove % 3 == 0) {
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
}