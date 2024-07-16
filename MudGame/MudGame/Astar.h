#pragma once
#include "stdafx.h"


//void astar(void);
void astar(int pre[][MAPSIZE_X], VERTEX* s, int visit[][MAPSIZE_X], QUEUE** Q, int g[][MAPSIZE_X], VERTEX* e, int i);
//VERTEX dequeue(void);
void enqueue(VERTEX v, QUEUE** Q, int i);
//void add_openlist(VERTEX);
void add_openlist(VERTEX v, int visit[][MAPSIZE_X], int g[][MAPSIZE_X], int pre[][MAPSIZE_X], VERTEX* e, QUEUE** Q, int i);

VERTEX dequeue(QUEUE** Q);


void UpdateFPS();
int calc_heuristic(VERTEX v, int c, int r, int* gx);
//void enqueue(VERTICAL);
int empty_queue(int i);
void print_character(int z);