#pragma once
#include <Windows.h>
#include <stdbool.h>

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

typedef struct vertex {
    int x;
    int y;
    int g;
} VERTEX;

typedef struct queue {
    VERTEX v;
    struct queue* next;
} QUEUE;


enum ColorType {
    BLACK,  	//0
    DARKBLUE,	//1
    DARKGREEN,	//2
    DARKSKYBLUE,    //3
    DARKRED,  	//4
    DARKPURPLE,	//5
    DARKYELLOW,	//6
    GRAY,		//7
    DARKGRAY,	//8
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
#define MAP_VERTICAL_ALIGN 32
#define ENEMY_NUM 2

// A* 알고리즘
#define UNDEF -1
#define CLOSED -3
#define DONTMOVE -1
#define INF 0

int map[MAPSIZE_Y][MAPSIZE_X];

int g[10][MAPSIZE_Y][MAPSIZE_X];
int visit[10][MAPSIZE_Y][MAPSIZE_X];
int pre[10][MAPSIZE_Y][MAPSIZE_X];
static DWORD lastTime;   //마지막 시간(temp변수)