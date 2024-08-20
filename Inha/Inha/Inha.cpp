#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StopWatch.h"
using namespace std;

/*
Q1. p.1343 문제 7.
*/

/*
// 챕터 17 예제 
#include <cmath>

int main()
{
	using namespace std;
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);

	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);
	cout << "왼쪽 정렬:\n";
	long n;

	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.setf(old, ios_base::floatfield);

	cout << "내부(internal) 정렬:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "오른쪽 정렬:\n";
	for (n = 1; n <= 41; n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	return 0;
}
*/
/*
// 챕터 17.16
#include <fstream>
#include <string>

int main()
{
	using namespace std;
	string filename;

	cout << "새 파일을 위한 이름을 입력하십시오: ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "비밀 번호 노출에 주의하십시오.\n";
	cout << "비밀 번호를 입력하십시오: ";
	float secret;
	cin >> secret;
	fout << "귀하의 비밀 번호는 " << secret << "입니다.\n";
	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " 파일의 내용은 다음과 같습니다:\n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "프로그램을 종료합니다.\n";
	fin.close();
	return 0;
}
*/
/*
// 챕터 17-19
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline() { while (std::cin.get() != '\n') continue; }

struct planet
{
	char name[20];
	double population;
	double g;
};

const char* file = "planets.dat";

int main()
{
	using namespace std;
	planet pl;
	cout << fixed << right;

	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);

	if (fin.is_open())
	{
		cout << file << " 파일의 현재 내용은 다음과 같습니다:\n";
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}

	cout << "행성의 이름을 입력하십시오 (끝내려면 빈 줄 입력) : \n";
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "행성의 인구를 입력하십시오: ";
		cin >> pl.population;
		cout << "행성의 중력가속도를 입력하십시오: ";
		cin >> pl.g;
		eatline();
		fout.write((char*)&pl, sizeof pl);
		cout << "행성의 이름을 입력하십시오 (끝내려면 빈 줄 입력) :\n";
		cin.get(pl.name, 20);
	}

	fout.close();

	fin.clear();

	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << file << " 파일의 개정된 내용은 다음과 같습니다.\n";
		while (fin.read((char*)&pl, sizeof pl))
		{
			cout << setw(20) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}

		fin.close();
	}

	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/
/*
// 챕터 17-20
#include <fstream>
#include <iomanip>
#include <cstdlib>

const int LIM = 20;
struct planet
{
	char name[LIM];
	double population;
	double g;	
};

const char* file = "planets.dat";
inline void eatline() { while (std::cin.get() != '\n') continue; }

int main()
{
	using namespace std;
	planet pl;
	cout << fixed;

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
		cout << file << " 파일의 현재 내용은 다음과 같습니다.\n";
		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}

		if (finout.eof())
			finout.clear();
		else
		{
			cerr << file << " 파일을 읽다가 에러 발생.\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 열 수 없습니다. 종료.\n";
		exit(EXIT_FAILURE);
	}

	cout << "수정할 레코드 번호를 입력하십시오:	";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 레코드 번호입니다. 종료.\n";
		exit(EXIT_FAILURE);
	}

	streampos place = rec * sizeof pl;
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "레코드를 찾다가 에러 발생.\n";
		exit(EXIT_FAILURE);
	}
	finout.read((char*)&pl, sizeof pl);
	cout << "현재 레코드의 내용: \n";
	cout << rec << ": " << setw(LIM) << pl.name << ": "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "행성의 이름을 입력하십시오: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "행성의 인구를 입력하십시오: ";
	cin >> pl.population;
	cout << "행성의 중력가속도를 입력하십시오: ";
	cin >> pl.g;
	finout.seekg(place);
	finout.write((char*)&pl, sizeof pl);
	if (finout.fail())
	{
		cerr << "쓰다가 에러 발생.\n";
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << " 파일의 개정된 내용은 다음과 같습니다:\n";
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}

	finout.close();
	cout << "프로그램을 종료합니다.\n";
}
*/