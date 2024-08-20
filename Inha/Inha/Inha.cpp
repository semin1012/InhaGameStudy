#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StopWatch.h"
using namespace std;

/*
Q1. p.1343 문제 7.
*/

#include <vector>
#include <iterator>
#include <algorithm>

void outint(int n) { cout << n << " "; }

vector<int> Lotto(int range, int count)
{
	vector<int> base;
	
	for (int i = 1; i <= range; i++)
		base.push_back(i);

	random_shuffle(base.begin(), base.end());

	return vector<int>(base.begin(), base.begin() + count);
}

int main()
{
	srand(time(NULL));
	vector<int> winners;
	winners = Lotto(45, 6);
	
	for_each(winners.begin(), winners.end(), outint);
}