#pragma once
#include "stdafx.h"

extern PLAYER player;
extern ENEMY enemy;

bool readStageFromFile(int stage);
bool readMaxCoinData();
void drawMap();
void printCoin();
void saveMaxCoin();
void game_start();
void initToReplay(int stage);
void printGameOver(bool* gameStart, bool* gameOver, int stage);
void printGameClearAtStage(bool* gameStart, bool* gameOver, int* stage, int nextStage);
void printGameAllStageClear(bool* gameStart, bool* gameClear, int* stage);
void gameStartScene(bool* gameStart, bool* gameClose);


void printTextGameStart(int i, int j);
void printTextGameClearAtStage(int i);
void printTextOnGameAllStageClear(int i);
void printTextGameOver(int i);
void scriptScene(bool* gameStart, bool* bScriptScene);