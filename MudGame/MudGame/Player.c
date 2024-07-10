#include <stdio.h>
#include <stdbool.h>
#include "stdafx.h"

extern PLAYER player;

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