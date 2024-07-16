#pragma once
#include "stdafx.h"

extern QUEUE* Q;
extern VERTEX s, e;	// start, end

extern QUEUE* f;
extern QUEUE** newq[10];
extern int count;
extern int size;

PLAYER player;
ENEMY enemy = { 1, 1 };

int dirX[8] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dirY[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int coinAllCnt = 0;
int coinNum = 0;
int stage = 0;
int enemySpeed = 3;
int enemyNum = 0;
ENEMY enemysPos[10];

int maxCoinNum = 0;