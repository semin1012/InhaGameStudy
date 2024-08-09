#include <cstring>
#include "StringBad.h"
using std::cout;

int StringBad::num_strings = 0;

StringBad::StringBad(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str << "\" ��ü ����\n";
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");
    num_strings++;
    cout << num_strings << ":\"" << str << "\" ����Ʈ ��ü ����\n";
}

StringBad::~StringBad()
{
    cout << "\"" << str << "\" ��ü �ı�, ";
    --num_strings;
    cout << "���� ��ü ��: " << num_strings << "\n";
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
    os << st.str;
    return os;
}
