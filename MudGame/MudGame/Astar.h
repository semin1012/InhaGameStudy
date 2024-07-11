#pragma once
#include "stdafx.h"


void astar(void);
VERTEX dequeue(void);

void UpdateFPS();
void add_openlist(VERTEX);
int calc_heuristic(VERTEX v, int c, int r, int* gx);
void enqueue(VERTICAL);
VERTEX dequeue(void);
int empty_queue(void);
void print_character(void);