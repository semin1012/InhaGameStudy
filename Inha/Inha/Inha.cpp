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
