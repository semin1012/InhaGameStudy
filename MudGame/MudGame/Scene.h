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
void printGameOver(bool* gameStart, bool* gameOver);
void printGameClearAtStage(bool* gameStart, bool* gameOver, int* stage, int nextStage);
void gameStartScene(bool* gameStart);