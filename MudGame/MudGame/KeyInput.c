#include <stdio.h>
#include "KeyInput.h"
#include "stdafx.h"

void inputDebugKey()
{
	for (int i = 0; i < MAPSIZE_Y; i++)
	{
		for (int j = 0; j < MAPSIZE_X; j++)
		{
			if (map[i][j] == 2)
			{
				map[i][j] = 0;
			}
		}
	}
}