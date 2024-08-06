#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

/*
Q1. 임의의 한 단어를 생성하고 사용자가 한번에
	한 문자만 추측하도록 해서 단어를 맞추는 게임.
	단어의 각 문자는 '*'으로 표시된다.
	사용자가 올바른 추측을 했을 때는 실제 문자가 화면에
	표시된다. 
	사용자가 단어를 맞추기를 끝냈을 때 실수한 횟수를 
	표시하고, 다른 단어를 계속할 것인지를 묻도록 한다.
	ex> 생성된 단어: apple
	> 단어 중 한 글자를 입력하시오. ***** > a
	>> a****
	> 단어 중 한 글자를 입력하시오. a**** > r
	>> r은 단어에 포함되지 않습니다.
	> 단어 중 한 글자를 입력하시오. a**** > a
	>> a는 이미 단어에 포함되어 있습니다.
	>> 총 xx 번 실패, 00 번 만에 정답! apple
#define STR_COUNT 5

void PrintInputSentence(char* c, char answer[]);
bool CheckInputCharacter(char* c, string* str, char answer[]);

int main()
{
	string strs[STR_COUNT] = { "apple", "banana", "grape", "blueberry", "tomato" };
	char answer[32] = {};
	char c;
	int rand_num, fail_count = 0, try_count = 0;

	srand(time(NULL));
	rand_num = rand() % STR_COUNT;

	cout << "생성된 단어: " << strs[rand_num] << "\n";

	for (int i = 0; i < strs[rand_num].length(); i++)
		answer[i] = '*';

	while (1)
	{
		PrintInputSentence(&c, answer);

		// 알파벳 입력 받기
		cout << " > ";
		cin >> c;
		
		try_count++;

		// 입력받은 것 체크, 실패라면 실패 횟수 증가
		if (CheckInputCharacter(&c, &strs[rand_num], answer) == false)
			fail_count++;

		cout << ">> " << answer << '\n';

		// 아직 정답이 아니라면 continue
		if (strs[rand_num] != answer) continue;

		// 정답이라면 시도 횟수 출력
		cout << "총 " << fail_count << "번 실패, " << try_count << "번 만에 정답! " << answer << '\n';

		cout << "다시 하려면 y를 입력하세요.\n";
		cin >> c;

		if (c == 'y' || c == 'Y')
		{
			// 다시 한다면 랜덤 단어로 다시 시작하기
			rand_num = rand() % STR_COUNT;
			cout << "생성된 단어: " << strs[rand_num] << "\n";
		}
		else break;
	}
}

void PrintInputSentence(char* c, char answer[])
{
	cout << "> 단어 중 한 글자를 입력하시오. ";
	cout << answer;
}

bool CheckInputCharacter(char* c, string* str, char answer[])
{
	bool correct = false;
	for (int i = 0; i < str->length(); i++)
	{
		if (answer[i] == *c)
		{
			cout << *c << "는 이미 단어에 포함되어 있습니다.\n";
			return false;
		}
		if ((*str)[i] == *c)
		{
			answer[i] = *c;
			correct = true;
		}
		else if (i == str->length() - 1 && correct == false)
		{
			cout << *c << "는 단어에 포함되지 않습니다.\n";
			return false;
		}
	}
	return true;
}
*/
