#include <cstring>
#include <cctype>
#include "String.h"
using std::cin;
using std::cout;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}

void String::stringup()
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ' ';
    }
}

void String::stringlow()
{
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += ' ';
    }
}

int String::has(char c)
{
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == c)
            result++;
    }
    return result;
}

String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

String& String::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

char& String::operator[](int i)
{
    return str[i];
}

const char& String::operator[](int i) const
{
    return str[i];
}

bool operator<(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String& st1, const String& st2)
{
    return st2 < st1;
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

const String& operator+(String& st1, const String& st2)
{
    char temp[String::CINLIM];
    strcpy(temp, st1.str);

    delete[] st1.str;

    st1.len = st1.len + st2.len;
    st1.str = new char[st1.len + 1];
    std::strcpy(st1.str, temp);
    std::strcat(st1.str, st2.str);
    return st1;
}

const String& operator+(const char* s, String& st2)
{
    char temp[String::CINLIM];
    strcpy(temp, st2.str);

    delete[] st2.str;

    st2.len = strlen(s) + st2.len;
    st2.str = new char[st2.len + 1];
    std::strcpy(st2.str, s);
    std::strcat(st2.str, temp);
    return st2;
}

ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
