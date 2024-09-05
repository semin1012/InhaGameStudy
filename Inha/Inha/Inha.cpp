#include <iostream>
#include <string>
#include <vector>
#include "StopWatch.h"
using namespace std;

void Print(string source, string find, int begin, int match, bool isMatch)
{
	cout << source << "\n";
	for (int i = 0; i < begin + match; i++)
		cout << " ";
	if (isMatch)
		cout << "+\n";
	else
		cout << "|\n";
	for (int i = 0; i < begin; i++)
		cout << " ";
	cout << find << "\n";
}

vector<int> GetBadMatchTable(string find)
{
	int findLength = find.length();
	int begin = findLength - 1, match = 0;

	vector<int> table(26, 0);


	// 뒤에서부터 검사

	for (int i = findLength - 1; i >= 0; i--)
	{
		// table 값이 0이라면 지금 구하는 게 최솟값임
		if (table[(int)find[i] - 'A'] == 0)
		{
			table[(int)find[i] - 'A'] = findLength - i - 1;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (table[i] == 0)
			table[i] = findLength;
	}

	return table;
}

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
				begin += match - table[match - 1];
				match -= table[match - 1];
			}
		}
	}

	return table;
}

void BoyerMoore(string source, string find)
{
	int sourceLength = source.length();
	int findLength = find.length();

	int begin = 0, match = 0;

	int count = 0;

	vector<int> table = GetBadMatchTable(find);

	while (begin + match < sourceLength)
	{
		count++;

		if (match < findLength && source[begin + findLength - 1 - match] == find[findLength - match - 1])
		{
			//cout << source << "\n";
			//for (int i = 0; i < begin + findLength - 1 - match; i++)
			//	cout << " ";
			//cout << "+\n";
			//for (int i = 0; i < begin; i++)
			//	cout << " ";
			//cout << find << "\n";

			match++;

			if (match == findLength)
				break;
		}

		else
		{
			//cout << source << "\n";
			//for (int i = 0; i < begin + findLength - 1- match; i++)
			//	cout << " ";
			//cout << "|\n";
			//for (int i = 0; i < begin; i++)
			//	cout << " ";
			//cout << find << "\n";

			{
				begin += table[(int)source[begin + findLength - 1] - 'A'];
				match = 0;
			}
		}
	}

	cout << "BoyerMoore 총 비교 횟수: " << count << "\n";
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

			match++;

			if (match == findLength)
				break;
		}

		else
		{

			if (match == 0)
				begin++;

			else
			{
				begin += match - table[match - 1];
				match -= table[match - 1];
			}
		}
	}

	cout << "KMP 총 비교 횟수: " << count << "\n";
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
			match++;

			if (match == findLength)
				break;
		}
		
		else 
		{
			match = 0;
			begin++;
		}
	}

	cout << "BruteForce 총 비교 횟수: " << count << "\n";
}



int main()
{
	string source = "ASDFSDFSDFSFABCABEWAFEWFDS";
	string find = "ABCAB";

	BruteForce(source, find);
	KMP(source, find);
	BoyerMoore(source, find);
}