#pragma once
#include "stdafx.h"

//extern QUEUE* Q[10];
//extern VERTEX s[10], e;	// start, end
//
//extern QUEUE* f;
//extern QUEUE** newq[10];
//extern int count[10];
//extern int size[10];

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
int enemyFixedNum = 0;
ENEMY enemysFixedPos[10];

int maxCoinNum = 0;

QUEUE* Q[10];
VERTEX s[10];
VERTEX e;	// start, end

QUEUE* f[10] = { NULL };
QUEUE** newq[10];
int count[10];
int size[10] = { 50, 50, 50, 50, 50, 50, 50, 50, 50, 50 };