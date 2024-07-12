#pragma once

#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"

void playingIntroBgm(void);
void playingSceneBgm(void);
void playingGetCoinSound(void);
void playingDeathSound(void);
void playingClearBgm(void);
void pauseBgm(MCI_OPEN_PARMS* bgm, int idwID);

MCI_OPEN_PARMS openBgm;		//bgm 구조체
MCI_OPEN_PARMS playingBgm;		//bgm 구조체
MCI_OPEN_PARMS coinSound;
MCI_OPEN_PARMS deathSound;
MCI_OPEN_PARMS clearSound;
int dwID;		// 배경음악 용도
int dwID_coin;	// 코인 용도

