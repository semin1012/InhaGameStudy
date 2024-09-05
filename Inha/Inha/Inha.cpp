#include <iostream>
#include <string>
#include <vector>
#include "StopWatch.h"
using namespace std;

vector<int> GetPatternTableBoyerMoore(string find)
{
	int findLength = find.length();
	int begin = findLength - 1, match = 0;

	vector<int> table(findLength, 0);

	while (begin - match > 0)
	{
		if (find[begin - match - 1] == find[findLength - match - 1])
		{
			match++;
			table[begin - match] = match;
		}

		else
		{
			if (match == 0)
				begin--;

			else
			{
				begin -= match + table[match - 1];
				match -= table[match - 1];
			}
		}
	}

	return table;
}

vector<int> GetPatternTable(string find)
{
	int findLength = find.length();
	int begin = 1, match = 0;

	vector<int> table(findLength, 0);

	while (begin + match > 0)
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

void BoyerMoore(string source, string find)
{
	int sourceLength = source.length();
	int findLength = find.length();

	int begin = sourceLength, match = 0;

	int count = 0;

	vector<int> table = GetPatternTableBoyerMoore(find);

	while (begin - findLength - 1 > 0)
	{
		count++;

		if (match < findLength && source[begin - match - 1] == find[findLength - match - 1])
		{
			/* ------------ 출력 ------------ */
			/*
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "+\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";
			*/
			/* ------------ 출력 ------------ */

			match++;

			if (match == findLength)
				break;
		}

		else
		{
			/* ------------ 출력 ------------ */
			/*
			cout << source << "\n";
			for (int i = 0; i < begin + match; i++)
				cout << " ";
			cout << "|\n";
			for (int i = 0; i < begin; i++)
				cout << " ";
			cout << find << "\n";
			*/
			/* ------------ 출력 ------------ */

			if (match == 0)
				begin--;

			else
			{
				begin -= match + table[match];
				match -= table[match];
			}
		}
	}

	for (int i = begin - findLength; i < begin; i++)
	{
		cout << source[i];
	}
	cout << endl;

	cout << begin << ", " << match << endl;
	cout << "총 비교 횟수: " << count << "\n";
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
	string source = "ABABCDABBAAEFGHA";
	string find = "ABBAA";

	// BruteForce(source, find);
	// KMP(source, find);
	BoyerMoore(source, find);
}