#include <stdio.h>
#include "consoleFunc.h"
#include "Scene.h"
#include "Sound.h"
#include "Enemy.h"
#include "Player.h"
#include "Astar.h"
#include "stdafx.h"

extern int coinAllCnt;
extern int coinNum;
extern DWORD lastTime;
extern int map[MAPSIZE_Y][MAPSIZE_X];
extern int enemySpeed;
extern int enemyNum;
extern ENEMY enemysPos[10];
extern int maxCoinNum;

extern int enemyFixedNum;
extern ENEMY enemysFixedPos[10];

extern MCI_OPEN_PARMS openBgm;
extern int dwID;

extern QUEUE* Q[10];
extern VERTEX s[10];
extern VERTEX e;	// start, end

extern QUEUE* f[10];
extern QUEUE** newq[10];
extern int count[10];
extern int size[10];

extern int cnt;
 
void printTextGameStart(int i, int j)
{
	if (j % 2 == 0) {
		ScreenPrint(44, 1, "        :$@@@@#;.");
		ScreenPrint(44, 2, "     .*@@@@@@@@##$,     ");
		ScreenPrint(44, 3, "     !@@@@@@@@@@@--@$     ");
		ScreenPrint(44, 4, "    .@@@@@@@@@@@@!;#=.    ");
		ScreenPrint(44, 5, "    .@@@@@@@@@@@@$=!~,     ");
		ScreenPrint(44, 6, "    ,@@@@@@@@@@=~.       ");
		ScreenPrint(44, 7, "    .@@@@@@@@@@@#=!-.     ");
		ScreenPrint(44, 8, "     ;@@@@@@@@@@@@$;     ");
		ScreenPrint(44, 9, "     .=@@@@@@@@@@@#,   ");
		ScreenPrint(44, 10, "       .:$@@@@#;.    ");


		//ScreenPrint(44, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠁⠀⠀⣴⣶⡄⠀⣶⣶⡄⠀⣴⣶⡄\n");
		//ScreenPrint(44, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣀⠀⠙⠋⠁⠀⠉⠋⠁⠀⠙⠋⠀\n");
		//ScreenPrint(44, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	}
	else {
		ScreenPrint(44, 1, "        :$@@@@#;.");
		ScreenPrint(44, 2, "     .*@@@@@@@@##$,     ");
		ScreenPrint(44, 3, "     !@@@@@@@@@@@--@$     ");
		ScreenPrint(44, 4, "    .@@@@@@@@@@@@!;#=.    ");
		ScreenPrint(44, 5, "    .@@@@@@@@@@@@$=!~,     ");
		ScreenPrint(44, 6, "    ,@@@@@@@@@@=~.       ");
		ScreenPrint(44, 7, "    .@@@@@@@@@@@#=!-.     ");
		ScreenPrint(44, 8, "     ;@@@@@@@@@@@@$;     ");
		ScreenPrint(44, 9, "     .=@@@@@@@@@@@#,   ");
		ScreenPrint(44, 10, "       .:$@@@@#;.    ");
		//ScreenPrint(44, 1, "     ⣀⣤⣴⣶⣶⣶⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 2, "   ⣠⣾⣿⣿⣿⣿⣿⣿⢿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 3, " ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣅⢀⣽⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 4, " ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡷⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 5, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠀⣶⣶⡄⠀⣴⣶⡄\n");
		//ScreenPrint(44, 6, " ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⠀⠉⠋⠁⠀⠙⠋⠀\n");
		//ScreenPrint(44, 7, " ⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 8, "  ⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 9, "   ⠈⠙⠿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
		//ScreenPrint(44, 10, "       ⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
	}
	setColor(WHITE);

	ScreenPrint(35, 12, " CCC  OOO  III N   N    RRRR  U   U N   N ");
	ScreenPrint(35, 13, "C    O   O  I  NN  N    R   R U   U NN  N ");
	ScreenPrint(35, 14, "C    O   O  I  N N N    RRRR  U   U N N N ");
	ScreenPrint(35, 15, "C    O   O  I  N  NN    R R   U   U N  NN ");
	ScreenPrint(35, 16, " CCC  OOO  III N   N    R  RR  UUU  N   N ");

	setColor(RED);
	ScreenPrint(44, 20, "Press Enter to Start");

	setColor(YELLOW);
	ScreenPrint(0, 18 + 4, "     ● ");
	setColor(YELLOW);
	ScreenPrint(j, 20 + 4, "     ♪      ♪       ♩       ♩   ♪    ♩               ♪  ♩ ♩ ♩      ♪    ♩♩     ♪            ♩ ♪ ♪ \n");
	ScreenPrint(j, 21 + 4, "♪       ♩   ♪       ♩ ♪   ♪    ♩   ♪       ♩  ♪      ♩   ♪    ♩      ♪   ♪ ♪       ♩      ♪     ♪");

	setColor(DARKGREEN);
	ScreenPrint(0, 22 + 4, "△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△△\n");
	setColor(BLUE);
	ScreenPrint(0, 23 + 4, "〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n");

	ScreenFlipping();

}
void printTextGameClearAtStage(int i)
{
	ScreenClear();

	setColor(DARKGRAY);
	ScreenPrint(8, (-2) + 3 + i, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, (-2) + 4 + i, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, (-2) + 5 + i, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, (-2) + 6 + i, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, (-2) + 7 + i, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, (-2) + 8 + i, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, (-2) + 9 + i, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, (-2) + 10 + i, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");

	setColor(DARKGRAY);
	ScreenPrint(8, 12 + i - 2, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, 13 + i - 2, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, 14 + i - 2, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, 15 + i - 2, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, 16 + i - 2, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, 17 + i - 2, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, 18 + i - 2, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, 19 + i - 2, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");

	setColor(DARKGRAY);
	ScreenPrint(8, 12 + i + 9 - 2, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, 13 + i + 9 - 2, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, 14 + i + 9 - 2, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, 15 + i + 9 - 2, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, 16 + i + 9 - 2, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, 17 + i + 9 - 2, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, 18 + i + 9 - 2, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, 19 + i + 9 - 2, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");


	setColor(YELLOW);
	ScreenPrint(38, 9 + 1, "┌───────────────────────────────────★\n");
	ScreenPrint(38, 10 + 1, "☆  탈출 성공!                      │ \n");
	ScreenPrint(38, 11 + 1, "│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━│ \n");
	ScreenPrint(38, 12 + 1, "│                                   │ \n");
	ScreenPrint(38, 13 + 1, "│  경찰을 피하기 성공했습니다.      │ \n");
	ScreenPrint(38, 14 + 1, "│                                   │ \n");
	ScreenPrint(38, 15 + 1, "│  계속 진행하려면 엔터를 누르세요. │ \n");
	ScreenPrint(38, 16 + 1, "│                                   │ \n");
	ScreenPrint(38, 17 + 1, "└───────────────────────────────────★ \n");

	ScreenFlipping();
}
void printTextOnGameAllStageClear(int i)
{
	ScreenClear();

	setColor(YELLOW);
	ScreenPrint(8, (-2) + 3 + i, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, (-2) + 4 + i, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, (-2) + 5 + i, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, (-2) + 6 + i, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, (-2) + 7 + i, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, (-2) + 8 + i, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, (-2) + 9 + i, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, (-2) + 10 + i, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");

	ScreenPrint(8, 12 + i - 2, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, 13 + i - 2, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, 14 + i - 2, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, 15 + i - 2, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, 16 + i - 2, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, 17 + i - 2, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, 18 + i - 2, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, 19 + i - 2, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");

	ScreenPrint(8, 12 + i + 9 - 2, "       _  _  _       _                _  _  _  _  _           _           _  _  _  _         _\n");
	ScreenPrint(8, 13 + i + 9 - 2, "    _ (_)(_)(_) _   (_)              (_)(_)(_)(_)(_)        _(_)_        (_)(_)(_)(_) _     (_)\n");
	ScreenPrint(8, 14 + i + 9 - 2, "   (_)         (_)  (_)              (_)                  _(_) (_)_      (_)         (_)    (_)\n");
	ScreenPrint(8, 15 + i + 9 - 2, "   (_)              (_)              (_) _  _           _(_)     (_)_    (_) _  _  _ (_)    (_)\n");
	ScreenPrint(8, 16 + i + 9 - 2, "   (_)              (_)              (_)(_)(_)         (_) _  _  _ (_)   (_)(_)(_)(_)       (_)\n");
	ScreenPrint(8, 17 + i + 9 - 2, "   (_)          _   (_)              (_)               (_)(_)(_)(_)(_)   (_)   (_) _\n");
	ScreenPrint(8, 18 + i + 9 - 2, "   (_) _  _  _ (_)  (_) _  _  _  _   (_) _  _  _  _    (_)         (_)   (_)      (_) _      _\n");
	ScreenPrint(8, 19 + i + 9 - 2, "      (_)(_)(_)     (_)(_)(_)(_)(_)  (_)(_)(_)(_)(_)   (_)         (_)   (_)         (_)    (_)\n");


	setColor(SKYBLUE);
	ScreenPrint(38, 9 + 1, "┌─────────────────────────────────────♣ \n");
	ScreenPrint(38, 10 + 1, "♧  축하합니다!                       │ \n");
	ScreenPrint(38, 11 + 1, "│  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━│ \n");
	ScreenPrint(38, 12 + 1, "│                                     │ \n");
	ScreenPrint(38, 13 + 1, "│  경찰을 따돌리고 코인을 모았습니다. │ \n");
	ScreenPrint(38, 14 + 1, "│                                     │ \n");
	ScreenPrint(38, 15 + 1, "│  다시 하려면 'R'을 누르세요.        │ \n");
	ScreenPrint(38, 16 + 1, "│                                     │ \n");
	ScreenPrint(38, 17 + 1, "└─────────────────────────────────────♣ \n");

}
void printTextGameOver(int i)
{
	ScreenClear();

	setColor(WHITE);
	ScreenPrint(10, 1 + 17 + i, ":'######::::::'###::::'##::::'##:'########:::::'#######::'##::::'##:'########:'########::'####:\n");
	ScreenPrint(10, 2 + 17 + i, "'##... ##::::'## ##::: ###::'###: ##.....:::::'##.... ##: ##:::: ##: ##.....:: ##.... ##: ####:\n");
	ScreenPrint(10, 3 + 17 + i, " ##:::..::::'##:. ##:: ####'####: ##:::::::::: ##:::: ##: ##:::: ##: ##::::::: ##:::: ##: ####:\n");
	ScreenPrint(10, 4 + 17 + i, " ##::'####:'##:::. ##: ## ### ##: ######:::::: ##:::: ##: ##:::: ##: ######::: ########::: ##::\n");
	ScreenPrint(10, 5 + 17 + i, " ##::: ##:: #########: ##. #: ##: ##...::::::: ##:::: ##:. ##:: ##:: ##...:::: ##.. ##::::..:::\n");
	ScreenPrint(10, 6 + 17 + i, " ##::: ##:: ##.... ##: ##:.:: ##: ##:::::::::: ##:::: ##::. ## ##::: ##::::::: ##::. ##::'####:\n");
	ScreenPrint(10, 7 + 17 + i, ". ######::: ##:::: ##: ##:::: ##: ########::::. #######::::. ###:::: ########: ##:::. ##: ####:\n");
	ScreenPrint(10, 8 + 17 + i, ":......::::..:::::..::..:::::..::........::::::.......::::::...:::::........::..:::::..::....::\n");

	setColor(DARKGRAY);
	ScreenPrint(80, 2 + 7, "┏┯┯┯┯┯┯┯┯┯┓\n");
	ScreenPrint(80, 3 + 7, "┃││∧ ∧││┃ 살려줘!!\n");
	ScreenPrint(80, 4 + 7, "┃│(ㅠㅠ)┃\n");
	ScreenPrint(80, 5 + 7, "┃│ф  ф││┃\n");
	ScreenPrint(80, 6 + 7, "┗┷┷┷┷┷┷┷┷┷┛\n");

	setColor(WHITE);
	ScreenPrint(13, 12 - 11, "＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿＿\n");
	ScreenPrint(13, 13 - 11, "|　도망 실패!　　　　　　　　　 　　 [－][口][×]|\n");
	ScreenPrint(13, 14 - 11, "|￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣|\n");
	ScreenPrint(13, 15 - 11, "|　경찰에게 잡혔습니다!                       　 |\n");
	ScreenPrint(13, 16 - 11, "|　다시 플레이를 원하면 r 을 누르세요 　　　　　 |\n");
	ScreenPrint(13, 17 - 11, "|　　　＿＿＿＿＿＿　　　　 　　＿＿＿＿＿＿　 　|\n");
	ScreenPrint(13, 18 - 11, "| 　　｜예　　　　 |　　　 　　|예　 　　   |　  |\n");
	ScreenPrint(13, 19 - 11, "|　　　￣￣￣￣￣￣　　　　　 　￣￣￣￣￣￣　　 |\n");
	ScreenPrint(13, 20 - 11, "￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣￣\n");


	ScreenFlipping();
}


bool readStageFromFile(int stage)
{
	FILE* ifp;
	char name[20];
	char num[2];

	// txt 파일 이름 파싱
	strcpy(name, "../data/map_");
	stage += 1;
	itoa(stage, num, 10);
	strcat(name, num);
	strcat(name, ".txt");
	// ex) name = "../data/map_1.txt"

	ifp = fopen(name, "rb");

	if (ifp == NULL) 
	{
		printf("%s 파일 읽기를 실패하여 종료합니다.\n", name);
		return false;
	}
	else 
	{
		for (int i = 0; i < MAPSIZE_Y; i++) 
		{
			for (int j = 0; j < MAPSIZE_X; j++) 
			{
				fscanf(ifp, "%d", &map[i][j]);
			}
		}
		// 총 코인 개수
		fscanf(ifp, "%d", &coinNum);

		// 플레이어 좌표
		fscanf(ifp, "%d%d", &player.x, &player.y);

		// 몬스터 좌표
		fscanf(ifp, "%d%d", &enemy.x, &enemy.y);

		// 몬스터 스피드 
		fscanf(ifp, "%d", &enemySpeed);

		// 몬스터 수
		fscanf(ifp, "%d", &enemyNum);

		for (int i = 0; i < enemyNum; i++)
		{
			fscanf(ifp, "%d%d", &enemysPos[i].x, &enemysPos[i].y);
		}

		// 고정된 몬스터 수
		fscanf(ifp, "%d", &enemyFixedNum);

		for (int i = 0; i < enemyFixedNum; i++)
		{
			fscanf(ifp, "%d%d", &enemysFixedPos[i].x, &enemysFixedPos[i].y);
		}

		fclose(ifp);
	}


	//if (stage == 1 )
	//{
	//	coinAllCnt = coinNum;
	//}
	//else 
	//{
	//	coinAllCnt += coinNum;
	//}

	return true;
}
bool readMaxCoinData()
{
	FILE* ifp;

	ifp = fopen("../data/max_coin.txt", "rb");

	if (ifp == NULL) 
	{
		printf("%s 파일 읽기를 실패하여 종료합니다.\n", "max_coin.txt");
		return false;
	}

	else 
	{
		fscanf(ifp, "%d", &maxCoinNum);
	}

	fclose(ifp);

	return true;
}

void drawMap()
{
	for (int i = 0; i < MAPSIZE_X; i++)
	{
		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			if (map[j][i] == 1) {
				setColor(DARKGRAY);
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, "■");
			}
			else if (map[j][i] == 0) {
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, " ");
			}
			else {
				setColor(YELLOW);
				ScreenPrint(i * 2 + MAP_VERTICAL_ALIGN, j, "＊");
			}
		}
		printf("\n");
	}
}

void gameStartScene(bool* gameStart)
{
	game_start();
	*gameStart = false;

	if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
	{
		pauseBgm(&openBgm, dwID);

		playingSceneBgm();
		*gameStart = true;

	}
}
void game_start()
{
	static int i = 0;
	static int j = 0;
	i++;
	ScreenClear();
	Sleep(50);

	setColor(YELLOW);

	if (i % 5 == 0)
	{
		j++;
	}

	printTextGameStart(i, j);
}

void initToReplay(int stage)
{
	FILE* ifp;
	char name[20];
	char num[2];

	// txt 파일 이름 파싱
	strcpy(name, "../data/map_");
	stage += 1;
	itoa(stage, num, 10);
	strcat(name, num);
	strcat(name, ".txt");
	// ex) name = "../data/map_1.txt"

	ifp = fopen(name, "rb");


	int tempMap[MAPSIZE_Y][MAPSIZE_X];

	if (ifp == NULL) {
		printf("%s 파일 읽기를 실패하여 종료합니다.\n", name);
		return;
	}
	else {
		for (int i = 0; i < MAPSIZE_Y; i++) {
			for (int j = 0; j < MAPSIZE_X; j++) {
				fscanf(ifp, "%d", &tempMap[i][j]);
			}
		}
		// 총 코인 개수
		fscanf(ifp, "%d", &coinNum);

		// 플레이어 좌표
		fscanf(ifp, "%d%d", &player.x, &player.y);

		// 몬스터 좌표
		fscanf(ifp, "%d%d", &enemy.x, &enemy.y);

		// 몬스터 스피드 
		fscanf(ifp, "%d", &enemySpeed);

		// 몬스터 수
		fscanf(ifp, "%d", &enemyNum);

		for (int i = 0; i < enemyNum; i++)
		{
			fscanf(ifp, "%d%d", &enemysPos[i].x, &enemysPos[i].y);
		}

		fclose(ifp);
	}


	//===============================

	//if (!readStageFromFile(stage)) {	// 읽기 실패하면 종료
	//	exit(0);
	//}

	playingSceneBgm();

	lastTime = clock();

	/*     A* 알고리즘      */
	// 벽
	for (int i = 0; i < 1; i++)
	{
		e.x = player.x;
		e.y = player.y;
		s[i].x = enemysPos[i].x;
		s[i].y = enemysPos[i].y;


		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			for (int z = 0; z < MAPSIZE_X; z++)
			{
				if (map[j][z] == 1)
					visit[i][j][z] = -2;	// WALL = -2
			}
		}
	}



}

void changeStage(int nextStage)
{
	pauseBgm(&clearSound, dwID);
	playingSceneBgm();

	//for (int i = 0; i < enemyNum; i++)
	//{
	//	for (int j = 0; j < count[i]; j++)
	//	{
	//		free(newq[i][j]);
	//	}

	//	count[i] = 0;
	//}

	if (!readStageFromFile(nextStage)) {	// 읽기 실패하면 종료
		exit(0);
	}

	lastTime = clock();

	/*     A* 알고리즘      */
	// 벽

	for (int i = 0; i < 1; i++)
	{
		e.x = player.x;
		e.y = player.y;
		s[i].x = enemysPos[i].x;
		s[i].y = enemysPos[i].y;

		for (int j = 0; j < MAPSIZE_Y; j++)
		{
			for (int z = 0; z < MAPSIZE_X; z++)
			{
				if (map[j][z] == 1)
					visit[i][j][z] = -2;	// WALL = -2
			}
		}
	}

}


void printCoin()
{
	char coins[5];
	itoa(player.coin, coins, 10);

	setColor(WHITE);
	char coinString[100] = "총 모은 코인: ";
	strcat(coinString, coins);
	ScreenPrint(60, 19, coinString);


	char bestCoins[5];
	itoa(maxCoinNum, bestCoins, 10);

	setColor(WHITE);
	char bestCoinString[100] = "최고 기록: ";
	strcat(bestCoinString, bestCoins);

	ScreenPrint(63, 20, bestCoinString);
	ScreenFlipping();
}
void saveMaxCoin()
{
	if (player.coin > maxCoinNum)
	{
		FILE* ifp;
		ifp = fopen("../data/max_coin.txt", "wb");

		fprintf(ifp, "%d", player.coin);

		maxCoinNum = player.coin;

		fclose(ifp);
	}
}
void printGameAllStageClear(bool* gameStart, bool* gameClear, int* stage)
{
	static int idir = 0;
	static int i = 0;
	static int j = 0;
	static bool playSound = false;

	if (playSound == false)
	{
		pauseBgm(&playingBgm, dwID);
		playingClearBgm();
		playSound = true;
	}

	printTextOnGameAllStageClear(i);
	saveMaxCoin();
	printCoin();

	if (idir == 0)
	{
		j++;
		if (j == 5) {
			i++;
			j = 0;
		}
		if (i == 1)
			idir = -1;
	}
	if (idir == -1)
	{
		j++;
		if (j == 5) {
			i--;
			j = 0;
		}
		if (i == -1)
			idir = 0;
	}

	// 'R' 누르면 다시 시작
	if ((GetAsyncKeyState('R') & 0x8000))
	{
		// TODO: 디버깅 때문에 해둠
		*stage = 0;
		player.coin = 0;
		coinAllCnt = 0;
		changeStage(*stage);
		UpdateFPS();

		playSound = false;
		*gameClear = false;
		*gameStart = false;
	}

	Sleep(50);
}

void printGameClearAtStage(bool* gameStart, bool* gameClear, int* stage, int nextStage)
{
	static int idir = 0;
	static int i = 0;
	static int j = 0;
	static bool playSound = false;

	if (playSound == false)
	{
		pauseBgm(&playingBgm, dwID);
		playingClearBgm();
		playSound = true;
	}

	printTextGameClearAtStage(i);


	if (idir == 0)
	{
		j++;
		if (j == 5) {
			i++;
			j = 0;
		}
		if (i == 1)
			idir = -1;
	}
	if (idir == -1)
	{
		j++;
		if (j == 5) {
			i--;
			j = 0;
		}
		if (i == -1)
			idir = 0;
	}

	// 엔터 누르면 다음 스테이지
	if ((GetAsyncKeyState(VK_RETURN) & 0x8000))
	{
		// TODO: 디버깅 때문에 해둠
		*stage = nextStage;
		*gameClear = false;
		changeStage(*stage);
		UpdateFPS();
		//cnt = 0;
		playSound = false;
	}

	Sleep(50);
}

void printGameOver(bool *gameStart, bool *gameOver, int stage)
{
	static int idir = 0;
	static int i = 0;
	if (idir == 0)
	{
		i++;
		if (i == 2)
			idir = -1;
	}
	if (idir == -1)
	{
		i--;
		if (i == -2)
			idir = 0;
	}

	printTextGameOver(i);

	if ((GetAsyncKeyState('R') & 0x8000) || (GetAsyncKeyState('r') & 0x8000))
	{
		if (stage == 0)
		{
			player.coin -= 50;
			if (player.coin < 0)
			{
				player.coin = 0;
			}
		}
		else if (stage == 1)
		{
			player.coin -= 70;
			if (player.coin < 0)
			{
				player.coin = 0;
			}
		}
		else if (stage == 2)
		{
			player.coin -= 100;
			if (player.coin < 0)
			{
				player.coin = 0;
			}
		}

		moveEnemy(true);
		*gameOver = false;
		initToReplay(stage);
		UpdateFPS();
		//*gameStart = false;
	}

	Sleep(75);
}
