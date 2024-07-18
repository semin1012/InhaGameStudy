#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
Q1. p.232 

struct Pizza
{
    string name;
    float diameter;
    float weight;
};

int main()
{
    // 7번 
    Pizza p1;
    cout << " > 피자 회사 이름, 피자의 지름, 피자의 중량을 순서대로 입력하세요: ";
    cin >> p1.name >> p1.diameter >> p1.weight;

    cout << " > " << p1.name << "의 정보: 지름 - " << p1.diameter << ", 중량 - " << p1.weight << endl << endl;

    // 8번
    Pizza *p2 = new Pizza;
    cout << " > 피자의 지름, 피자 회사 이름, 피자의 중량을 순서대로 입력하세요: ";
    cin >> p2->diameter >> p2->name >> p2->weight;

    cout << " > " << p2->name << "의 정보: 지름 - " << p2->diameter << ", 중량 - " << p2->weight << endl;
}
*/


/*
Q2. 단어를 입력받아서 회문인지 여부를 판단해서 결과를 출력하는 프로그램을 작성하라.
    ex >
        단어 입력: level
        level 은 회문입니다.

        단어 입력: animal
        animal 은 회문이 아닙니다.
*/

int main()
{
    while ( 1 )
    {
        string str, temp;
        cout << " > 단어 입력: ";
        cin >> str;

        for (int i = str.length() - 1; i >= 0; i--)
        {
            temp += str[i];
        }

        if (temp == str)
        {
            cout << " > " << str << " 은 회문입니다. \n\n";
        }
        else cout << " > " << str << " 은 회문이 아닙니다\n\n";
    }
}