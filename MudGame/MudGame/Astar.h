#pragma once
#include "stdafx.h"


//void astar(void);
void astar(int pre[][MAPSIZE_X], VERTEX* s, int visit[][MAPSIZE_X], QUEUE** Q, int g[][MAPSIZE_X], VERTEX* e);
//VERTEX dequeue(void);
void enqueue(VERTEX* v, QUEUE** Q);
//void add_openlist(VERTEX);
void add_openlist(VERTEX* v, int visit[][MAPSIZE_X], int g[][MAPSIZE_X], int pre[][MAPSIZE_X], VERTEX* e, QUEUE** Q);

VERTEX dequeue(QUEUE* Q);


void UpdateFPS();
int calc_heuristic(VERTEX v, int c, int r, int* gx);
//void enqueue(VERTICAL);
int empty_queue(void);
void print_character(void);