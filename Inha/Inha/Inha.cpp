#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//int main(void)
//{
//    int a = 10, b = 20;
//   
//    cout << "\n";
//    cout << "  =================\n";
//    cout << "  Hello World!" << endl;
//    cout << "  " << a + b << endl;
//    cout << "  a: " << a << ", b: " << b << endl;
//    cout << "  =================\n\n";
//
//    cout << " > Input Num: ";
//    cin >> a;
//
//    cout << " a: " << a << endl;
//}

/*
// p.69 
void printBline()
{
    cout << "Three blind mice" << endl;
}
void printRun()
{
    cout << "See how they run" << endl;
}
void change()
{
    int c, f;
    cout << "섭씨 온도를 입력하고 Enter 키를 누르십시오: ";
    cin >> c;
    f = 1.8 * c + 32.0;
    cout << "섭씨 " << c << "도는 화씨로 " << f << "입니다." << endl;
} 

int main()
{
    // 2번
    int mail;
    float km;
    cout << "마일 단위의 거리를 입력하세요: ";
    cin >> mail;

    km = mail * 1.60934;
    cout << "킬로미터 단위 환산: " << km << endl;
    
    // 3번
    printBline();
    printBline();
    printRun();
    printRun();

    // 5번
    change();
}
*/
/*
// Q1. p129
//  키를 정수형 센티미터 단위로 묻고 그 값을 미터와 센티미터 단위로 변환하는 간단한 프로그램을 작성하라.
//  입력해야 할 곳을 사용자에게 지시하기 위해 밑줄 문자를 사용하고 환산 인수로 const 기호 상수를 사용하라.
int main()
{
    int centi;
    float m;
    const int centiToM = 100;
    cout << "센티미터 단위의 키를 입력하세요: ___ cm\b\b\b\b\b\b";
    cin >> centi;

    m = centi / (float)centiToM;

    cout << "미터 단위의 키: " << m << " m";
}

// Q2. p129 3번
int main()
{
    int d, b, c;
    float result = 0;

    cout << "위도를 도, 분, 초 단위로 입력하시오" << endl;
    cout << "먼저, 도각을 입력하시오: ";
    cin >> d;
    cout << "다음에, 분각을 입력하시오: ";
    cin >> b;
    cout << "끝으로, 초각을 입력하시오: ";
    cin >> c;

    result = d + b / 60.f + c / 60.f / 60.f;
    cout << d << "도, " << b << "분, " << c << "초 = " << result << "도\n";
}
// Q3. p129 5번
int main()
{
    double world, usa;
    float percent;
    
    cout << "세계 인구수를 입력하시오: ";
    cin >> world;
    cout << "미국의 인구수를 입력하시오: ";
    cin >> usa;

    percent = usa / world * 100;
    cout << "세계 인구수에서 미국이 차지하는 비중은 " << percent << "%이다. \n";
}
*/
// Q4. p129 7번
int main()
{
    while (1)
    {
        float europe, USA;
        cout << "유럽 스타일의 휘발유 소비량을 입력하시오: ";
        cin >> europe;

        USA = 3.875 / (europe) * 62.14;
        cout << europe << " liters/100km는 약 " << (int)USA << " mpg이다.\n\n";
    }
}
/*
*/