#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;



int main()
{
	for (int i = 0; i < 120; i++)
	{
		printf("{");
		for (int j = 0; j < 30; j++) {
			printf("%d,", 0);
		}
		printf("},\n");
	}
}