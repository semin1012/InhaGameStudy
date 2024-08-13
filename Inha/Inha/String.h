#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;

public:
	String(const char* s);
	String();
	String(const String& st);
	~String();
	int length() const { return len; }
	void stringup();
	void stringlow();
	int has(char c);

	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend const String& operator+(String& st1, const String& st2);
	friend const String& operator+(const char* s, String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& os, String& st);

	static int HowMany();
};

