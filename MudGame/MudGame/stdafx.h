#pragma once

typedef struct _PLAYER
{
    int x; // 출력기준좌표
    int y;
    int coin;
} PLAYER;

typedef struct _ENEMY
{
    int x;
    int y;
} ENEMY;

enum ColorType {
    BLACK,  	//0
    DARKBLUE,	//1
    DARKGREEN,	//2
    DARKSKYBLUE,    //3
    DARKRED,  	//4
    DARKPURPLE,	//5
    DARKYELLOW,	//6
    GRAY,		//7
    DarkGray,	//8
    BLUE,		//9
    GREEN,		//10
    SKYBLUE,	//11
    RED,		//12
    PURPLE,		//13
    YELLOW,		//14
    WHITE		//15
} COLOR;


#define MAPSIZE_X 25
#define MAPSIZE_Y 25

int map[MAPSIZE_Y][MAPSIZE_X];
