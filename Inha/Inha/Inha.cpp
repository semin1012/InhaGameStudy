#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// p.232 문제 5, 6, 9번
struct CandyBar
{
    string name;
    float weight;
    int kcal;
};

#define CANDY_NUM 5

int main()
{
    CandyBar snack = { "Mocha Munch", 2.3, 350 };

    // 5번 출력
    cout << "이름: " << snack.name << ", 무게: " << snack.weight << ", 칼로리: " << snack.kcal << endl;

    cout << endl;

    // 6번
    CandyBar candys[CANDY_NUM] = {
        {"apple candy", 2.0, 100 },
        {"banana candy", 2.1, 122},
        {"blueberry candy", 1.9, 118},
        {"cherry candy", 2.0, 130},
        {"red candy", 1.95, 123}
    };

    for (int i = 0; i < CANDY_NUM; i++)
    {
        cout << "이름: " << candys[i].name << ", 무게: " << candys[i].weight << ", 칼로리: " << candys[i].kcal << endl;
    }

    cout << endl; 

    // 7번
    CandyBar *pCandys = new CandyBar[5];
    if (pCandys)
    {
        for (int i = 0; i < CANDY_NUM; i++)
        {
            cout << "캔디의 이름, 무게, 칼로리를 입력하세요: ";
            cin >> pCandys[i].name >> pCandys[i].weight >> pCandys[i].kcal;
        }

        for (int i = 0; i < CANDY_NUM; i++)
        {
            cout << "이름: " << pCandys[i].name << ", 무게: " << pCandys[i].weight << ", 칼로리: " << pCandys[i].kcal << endl;
        }

        delete[] pCandys;
    }
}