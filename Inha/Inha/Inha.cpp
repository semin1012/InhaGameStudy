#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/* 
Q1. 점(x1, y1) 를 입력받아 그 점이 (x0, y0)를 중심으로 하고
	반지름 r 인 원의 내부에 존재하는지 검사하는 프로그램을 작성하라.
	ex>
		input > r : 10, x0 = 0, y0 = 0, x1 = 4, y1 = 5
		output > 점 (4, 5)는 중점이 (0, 0)이고 반지름이 10인 
		원 안에 있습니다.

	점이 원 내부에 존재하는지 검사하는 함수를 만들고,
	점(x1, y1), (x0, y0)를 인자로 넘겨줄 때 포인터 구조체를 
	이용해서 만들 것
*/

/*
Q2. 선1의 두 점 (x1, y1)과 (x2, y2), 선2의 두 점 (x3, y3)과 (x4, y4)로 주어진
	두 선의 교차점을 구하는 프로그램을 작성하라.
	크래머 공식을 이용하라. 

	ex> 점 4개 입력: x1, y1, x2, y2, x3, y3, x4, y4
		>> 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
		>> 교차점은 ( 000, 000 ) 이다. 

		>> 2 2 7 6.0 4.0 2.0 -1.0 -2.0
		>> 두 직선은 평행이다. 
*/

/*
// p.472 Listing 08.2
int main()
{
	int rats = 101;
	int& rodents = rats;

	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats의 주소 = " << &rats;
	cout << ", rodents의 주소 = " << &rodents << endl;

	// &(참조 변수)는 원본 변수와 같은 값, 같은 주소를 가지고 있다. 
	return 0;
}
*/
/*
// p.476 Listing 08.4
void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);

int main()
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "참조를 이용하여 내용들을 교환:\n";
	swapr(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "포인터 이용하여 내용들을 다시 교환:\n";
	swapp(&wallet1, &wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";

	cout << "값을 전달하여 내용 교환 시도:\n";
	swapv(wallet1, wallet2);
	cout << "지갑 1 = " << wallet1 << "원";
	cout << ", 지갑 2 = " << wallet2 << "원\n";
}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
*/
/*
// p.486 Listing 08.6
struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws& ft);
void set_pc(free_throws& ft);
free_throws& accumulate(free_throws& target, const free_throws& source);

int main()
{
	free_throws one = {"Ifelsa Branch", 13, 14};
	free_throws two = { "Andor Knott", 10, 16 };
	free_throws three = { "Minnie Max", 7, 9 };
	free_throws four = { "Whily Looper", 5, 9 };
	free_throws five = { "Long Long", 6, 14 };
	free_throws team = { "Throwgoods", 0, 0 };

	free_throws dup;
	set_pc(one);
	display(one);
	accumulate(team, one);
	display(team);

	display(accumulate(team, two));
	accumulate(accumulate(team, three), four);
	display(team);

	dup = accumulate(team, five);
	cout << "team 출력: \n";
	display(team);
	cout << "대입 이후 dup 출력:\n";
	display(dup);
	set_pc(four);

	accumulate(dup, five) = four;
	cout << "문제 소지가 있는 대입 이후 dup 출력:\n";
	display(dup);
	return 0;
}

void display(const free_throws& ft)
{
	cout << "Name: " << ft.name << "\n";
	cout << "Made: " << ft.made << "\n";
	cout << "Attempts: " << ft.attempts << "\n";
	cout << "Percent: " << ft.percent << "\n";
}

void set_pc(free_throws& ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f * float(ft.made) / float(ft.attempts);
	else ft.percent = 0;
}

free_throws& accumulate(free_throws& target, const free_throws& source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}
*/
/*
// p.495 Listing 08.7
string version1(const string& s1, const string& s2);
const string& version2(string& s1, const string& s2);
const string& version3(string& s1, const string& s2);

int main()
{
	string input;
	string copy;
	string result;

	cout << "문자열을 입력하시오: ";
	getline(cin, input);
	copy = input;
	cout << "입력한 문자열: " << input << endl;
	result = version1(input, "***");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	result = version2(input, "###");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;

	cout << "원래 문자열 재설정\n";
	input = copy;
	result = version3(input, "@@@");
	cout << "바뀐 문자열: " << result << endl;
	cout << "원래 문자열: " << input << endl;
	
	return 0;
}

string version1(const string& s1, const string& s2)
{
	string temp;

	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string& version3(string& s1, const string& s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}
*/
/*
// p.501 Listing 08.8
#include <fstream>
#include <cstdlib>

void file_it(ostream& os, double fo, const double fe[], int n);
const int LIMIT = 5;

int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << fn << " 파일을 열 수 없습니다. 끝.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "대물렌즈 초점거리를 " "mm 단위로 입력하십시오: ";
	cin >> objective;
	double eps[LIMIT];
	cout << LIMIT << "가지 대안렌즈의 초점거리를 " "mm 단위로 입력하십시오:\n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "대안렌즈 #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);
	file_it(cout, objective, eps, LIMIT);
	cout << "종료\n";
	return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);
	os.precision(0);
	os << "대물렌즈의 초점거리: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(17);
	os << "대안렌즈 초점거리";
	os.width(15);
	os << "확대배율" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(17);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);
}
*/
/**/
// p.506 Listing 08.9
const int ArSize = 80;
char* left(const char* str, int n = 3);

int main()
{
	char sample[ArSize];
	cout << "문자열을 입력하십시오:\n";
	cin.get(sample, ArSize);
	char* ps = left(sample, 85);
	cout << ps << endl;
	delete[] ps;
	ps = left(sample);
	cout << ps << endl;
	delete[] ps;
	return 0;
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}
