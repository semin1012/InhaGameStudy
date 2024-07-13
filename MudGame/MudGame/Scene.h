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
bool readMaxCoinData();
void drawMap();
void printCoin();
void game_start();
void initToReplay(int stage);
void printGameOver(bool* gameStart, bool* gameOver, int stage);
void printGameClearAtStage(bool* gameStart, bool* gameOver, int* stage, int nextStage);
void printGameAllStageClear(bool* gameStart, bool* gameClear, int* stage);
void gameStartScene(bool* gameStart);