#include <iostream>
#include <string>
#include <vector>
#include "StopWatch.h"
using namespace std;

vector<int> GetPatternTable(string find)
{
	int findLength = find.length();
	int begin = 1, match = 0;

	vector<int> table(findLength, 0);

	while (begin + match < findLength)
	{
		if (find[begin + match] == find[match])
		{
			match++;
			table[begin + match - 1] = match;
		}

		else
		{
			if (match == 0)
				begin++;

			else
			{
				begin += match - table[match-1];
				match -= table[match-1];
			}
		}
	}

	return table;
}

void KMP(string source, string find)
{
	int sourceLength = source.length();
	int findLength = find.length();
	
	int begin = 0, match = 0;

	int count = 0;

	vector<int> table = GetPatternTable(find);

	while (begin < sourceLength - findLength)
	{
		count++;

		if (match < findLength && source[begin + match] == find[match])
		{
			/* ------------ 출력 ------------ */
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "+\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";
			/* ------------ 출력 ------------ */

			match++;

			if (match == findLength)
				break;
		}

		else
		{
			/* ------------ 출력 ------------ */
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "|\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";
			/* ------------ 출력 ------------ */

			if (match == 0)
				begin++;

			else
			{
				begin += match - table[match - 1];
				match -= table[match - 1];
			}
		}
	}

	cout << "총 비교 횟수: " << count << "\n";
}

void BruteForce(string source, string find)
{
	int sourceLength = source.length();
	int findLength = find.length();
	int begin = 0, match = 0;

	int count = 0;

	while (begin < sourceLength - findLength)
	{
		count++;
		if (source[begin + match] == find[match])
		{
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "+\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";

			match++;

			if (match == findLength)
				break;
		}
		
		else 
		{
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "|\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";

			match = 0;
			begin++;
		}
	}

	cout << "총 비교 횟수: " << count << "\n";
}

int main()
{
	string source = "ABABCDEFGHA";
	string find = "ABC";

	BruteForce(source, find);
	// KMP(source, find);
}