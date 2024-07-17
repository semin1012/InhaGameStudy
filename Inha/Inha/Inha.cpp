#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
// Listing 04.2
int main()
{
    using namespace std;
    const int Size = 15;
    char name1[Size];
    char name2[Size] = "C++owboy";

    cout << "안녕하세요! 저는 " << name2;
    cout << "입니다! 실례지만 성함이?\n";
    cin.getline(name1, Size);
    cout << "아, " << name1 << " 씨! 당신의 이름은 ";
    cout << strlen(name1) << "자입니다만\n";
    cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
    cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
    name2[3] = '\0';
    cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
    cout << name2 << endl;
    return 0;
}
// Listing 04.6
int main()
{
    cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
    int year;
    (cin >> year).get();
    cout << "사시는 도시를 말씀해 주시겠습니까?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "아파트 입주 연도: " << year << endl;
    cout << "도시: " << address << endl;
    cout << "등록이 완료되었습니다!\n";
    return 0;
}
// Listing 04.8
int main()
{
    string s1 = "penguin";
    string s2, s3;

    cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
    s2 = s1;
    cout << "s1: " << s1 << ", s2: " << s2 << endl;
    cout << "string 객체에 C 스타일 문자열을 대입할 수 있다.\n";
    cout << "s2 = \"buzzard\"\n";
    s2 = "buzzard";
    cout << "s2: " << s2 << endl;
    cout << "string 객체들을 결합할 수 있다: s3 = s1 + s2\n";
    s3 = s1 + s2;
    cout << "s3: " << s3 << endl;
    cout << "string 객체들을 추가할 수 있다.\n";
    s1 += s2;
    cout << "s1 += s2 --> s1 = " << s1 << endl;
    s2 += " for a day";
    cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;
}
// Listring 04.10
int main()
{
    char charr[20];
    string str;

    cout << "입력 이전에 charr에 있는 문자열의 길이: " << strlen(charr) << endl;
    cout << "입력 이전에 str에 있는 문자열의 길이: " << str.size() << endl;
    cout << "텍스트 한 행을 입력하시오:\n";
    cin.getline(charr, 20);
    cout << "입력한 텍스트: " << charr << endl;
    cout << "또 다른 텍스트 한 행을 입력하시오:\n";
    getline(cin, str);
    cout << "입력한 텍스트: " << str << endl;
    cout << "입력 이후에 charr에 있는 문자열의 길이: " << strlen(charr) << endl;
    cout << "입력 이후에 str에 있는 문자열의 길이: " << str.size() << endl;
}
// Listing 04.18
int main()
{
    double* p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1]은 " << p3[1] << "입니다.\n";
    p3 = p3 + 1;
    cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
    cout << "p3[1]이 " << p3[1] << "입니다.\n";
    p3 = p3 - 1;
    delete[] p3;
    return 0;
}
*/
// Listing 04.24
#include <vector>
#include <array>
int main()
{
    double a1[4] = { 1.2, 2.4, 3.6, 4.8 };
    vector<double> a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;
    
    array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.41 };
    array<double, 4> a4;
    a4 = a3;

    cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;

    a1[-2] = 20.2;
    cout << "a1[-2] : " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;
}