#include <stdio.h>
#include <stdbool.h>
#include "stdafx.h"
#include "Enemy.h"

extern ENEMY enemy;
extern int dirX[];
extern int dirY[];
extern PLAYER player;
extern int enemySpeed;

void moveEnemy()
{
	static int enemyMove = 0;
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
}

bool isOverlapEnemy()
{
	if (enemy.x == player.x && enemy.y == player.y) {
		return true;
	}
	else return false;
}