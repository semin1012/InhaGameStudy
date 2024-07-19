#define _CRT_SECURE_NO_WARNINGS
/*
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*
Q3. 1~10 사이의 정수를 입력 받아 다음과 같은 형태로 출력하는 프로그램을 작성하라.

    ex> 라인수 입력: 5
            1
           212
          32123
         4321234
        543212345

#include <time.h>
#include <ctime>
int main()
{
    time_t start, end;
    start = time(NULL);



    int n;
    cout << "> 라인수 입력: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = i + 1; j >= 1; j--)
        {
            cout << j;
        }
        for (int j = 2; j <= i+1; j++)
        {
            cout << j;
        }
        cout << endl;
    }

    cout << endl;

    end = time(NULL);

    cout << end - start << endl;
}
*/
/*
*/
struct Car
{
    string company;
    int year;
};

int main()
{
    int n;
    Car* car;
    cout << "몇 대의 차를 목록으로 관리하시겠습니까?: ";
    cin >> n;

    car = new Car[n];

    for (int i = 0; i < n; i++)
    {
        cout << "자동차 #" << i + 1 << ": " << endl;
        cout << "> 제작업체: ";
        cin >> car[i].company;
        cout << "> 제작년도: ";
        cin >> car[i].year;
    }

    cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다.\n";
    for (int i = 0; i < n; i++)
    {
        cout << car[i].year << "년형 " << car[i].company << endl;
    }

    delete[] car;
}
/*
#include <vector>
#include <cstring>

int main()
{
    vector<string> str;
    int cnt = 0;
    while (1)
    {
        string temp;
        cin >> temp;
        if (temp == "done")
            break;

        str.push_back(temp);
        cnt++;
    }

    for (int i = 0; i < cnt; i++)
    {
        cout << str[i] << " ";
    }

    cout << endl << "총 " << cnt << " 단어가 입력되었습니다.\n";
}

/* 
Q5. 10진수를 각 진수로 변환하는 프로그램을 작성하라. 
    확장... 각 진수끼리 변환 프로그램을 작성하라.
    (2~36 진수 사이 서로 변환) 
    
    16진수 3B -> 2진수 ?
    2진수 1001 -> 16진수 ?

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int toBinary(char* temp, int nums, int number)
{
    int cnt = 0;

    char str[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'N', 'M', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    // number진수로 계산
    while (nums)
    {
        char ch[2];
        int a = nums % number;
        temp[cnt++] = str[a];
        nums /= number;
    }

    return cnt;
}

int toChange(int in, int out, char* num, char* result)
{
    char str[36] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'N', 'M', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    int cnt = 0;
    int n = 0;
    
    // 10진수로 계산
    for (int j = strlen(num)-1; j >= 0; j--)
    {
        for (int i = 0; i < 36; i++)
        {
            if (str[i] == num[j])
            {
                if (j == strlen(num) - 1)
                    n += i;
                else
                {
                    n += in * i * (j + 1);
                }
            }
        }
    }

    int i = 0;

    // 10진수를 out진수로 계산
    while (n)
    {
        char ch[2];
        int a = n % out;
        result[cnt++] = str[a];
        n /= out;
    }


    return cnt;
}

int main()
{
    char n[10];
    int result = 0;
    int number;
    int in, out;
    char inNum[10];
    char resultStr[20];
    while (1)
    {
        printf("10진수를 입력하세요: ");
        scanf("%s", &n);
        printf("몇 진수로 변환할지 입력하세요: ");
        scanf("%d", &number);
        printf("%2d진수: %s\n", 10, n);

        int nums = atoi(n);
        char temp[10];
        int cnt = toBinary(temp, nums, number);

        printf("%2d진수: ", number);
        for (int i = cnt-1; i >= 0; i--)
        {
            printf("%c", temp[i]);
        }
        printf("\n\n");

        printf("> 입력할 수의 진수: ");
        scanf("%d", &in);
        printf("> 해당 진수로 수 입력: ");
        scanf("%s", &inNum);
        printf("> 변경할 수의 진수 입력: ");
        scanf("%d", &out);

        printf("%2d진수: %s\n", in, inNum);
        cnt = toChange(in, out, inNum, resultStr);

        printf("%2d진수: ", out);
        for (int i = cnt - 1; i >= 0; i--)
        {
            printf("%c", resultStr[i]);
        }
        printf("\n\n");
    }
}
*/