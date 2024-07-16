#include <stdio.h>
#include "stdafx.h"
#include "Sound.h"



void playingIntroBgm(void)
{
	//openBgm.lpstrElementName = TEXT("../data/Intro.mp3");
	//openBgm.lpstrDeviceType = TEXT("mpegvideo");    //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&openBgm);
	//dwID = openBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&openBgm);    //음악 반복 재생
}

void playingSceneBgm(void)
{
	//playingBgm.lpstrElementName = TEXT("../data/Cutscene_sound.mp3");
	//playingBgm.lpstrDeviceType = TEXT("mpegvideo");    //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&playingBgm);
	//dwID = playingBgm.wDeviceID;
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&playingBgm);    //음악 반복 재생
}

void playingGetCoinSound(void)
{
	//coinSound.lpstrElementName = TEXT("../data/coin.mp3");
	//coinSound.lpstrDeviceType = TEXT("mpegvideo");    //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&coinSound);
	//dwID_coin = coinSound.wDeviceID;
	//mciSendCommand(dwID_coin, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
	//mciSendCommand(dwID_coin, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&coinSound); //음악을 한 번 재생
}

void playingDeathSound(void)
{
	//deathSound.lpstrElementName = TEXT("../data/Death.mp3");
	//deathSound.lpstrDeviceType = TEXT("mpegvideo");    //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&deathSound);
	//dwID = deathSound.wDeviceID;
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
	//mciSendCommand(dwID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&deathSound); //음악을 한 번 재생
}

void playingClearBgm(void)
{
	//clearSound.lpstrElementName = TEXT("../data/clear.mp3");
	//clearSound.lpstrDeviceType = TEXT("mpegvideo");    //mp3 형식
	//mciSendCommand(0, MCI_OPEN, MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)(LPVOID)&clearSound);
	//dwID = clearSound.wDeviceID;
	//mciSendCommand(dwID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL); //음원 재생 위치를 처음으로 초기화
	//mciSendCommand(dwID, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&clearSound); //음악을 한 번 재생
}

void pauseBgm(MCI_OPEN_PARMS *bgm, int idwID)
{
	//mciSendCommand(idwID, MCI_PAUSE, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)bgm);    //음악 반복 재생
}