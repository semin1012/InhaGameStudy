#pragma once
#include "stdafx.h"

extern int count;
extern QUEUE** newq;
extern VERTEX e;
extern VERTEX s;
extern QUEUE* Q;
extern PLAYER player;
extern ENEMY enemy;

bool readStageFromFile(int stage);
void drawMap();
void game_start();
void printGameOver();
void gameStartScene(bool* gameStart);