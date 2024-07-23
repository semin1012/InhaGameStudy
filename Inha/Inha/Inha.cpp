#define _CRT_SECURE_NO_WARNINGS
/*
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
const int Max = 5;
// Listing 06.13
int main()
{
	using namespace std;
	double fish[Max];
	cout << "오늘 낚은 물고기의 무게를 입력하십시오.\n";
	cout << "물고기는 최대 " << Max << "마리까지 낚을 수 있습니다.\n"
		<< "<입력을 끝내려면 q를 누르십시오.>\n";
	cout << "fish #1: ";
	int i = 0;
	while (i < Max && cin >> fish[i]) {
		if (++i < Max)
			cout << "fish #" << i + 1 << ": ";
	}

	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];

	if (i == 0)
		cout << "물고기를 한 마리도 낚지 못하셨군요.\n";
	else cout << "물고기 " << i << "마리의 평균 무게는 " << total / i << "그램입니다.\n";
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/
/*
// Listing 06.14
const int Max = 5;
int main()
{
	int golf[Max];
	cout << "골프 점수를 입력하세요.\n";
	cout << "총 " << Max << " 라운드 점수를 입력해야 합니다.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while ( !(cin >> golf[i] ))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "골프 점수를 입력하십시오: ";
		}
	}
	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << "총 " << Max << "라운드의 평균 점수 = " << total / Max << endl;
	return 0;
}
#include <fstream>

int main()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outfile;
	outfile.open("../data/carinfo.txt");

	cout << "자동차 메이커와 차종을 입력하시오: ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오: ";
	cin >> year;
	cout << "구입 가격을 입력하시오: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "메이커와 차종: " << automobile << endl;
	cout << "연식: " << year << endl;
	cout << "구입 가격 $" << a_price << endl;
	cout << "현재 가격 $" << d_price << endl;

	outfile << fixed;
	outfile.precision(2);
	outfile.setf(ios_base::showpoint);
	outfile << "메이커와 차종: " << automobile << endl;
	outfile << "연식: " << year << endl;
	outfile << "구입 가격 $ " << a_price << endl;
	outfile << "현재 가격 $ " << d_price << endl;

	outfile.close();

	return 0;
}
*/

/*
Q1. 비행기의 가속도 a와 이륙속도 v가 주어졌을 때,
	비행기가 이륙하기 위한 최소 활주 길이를 계산하는 프로그램을 작성하라.
	(길이 = v^2 / 2a)
	사용자에게 m/s 단위로 v와 m/s^2 단위로 a를 입력받도록 알려주고,
	최소 활주 길이를 출력하는 프로그램을 작성하라.
	ex > Speed and Accelation : 60 3.5
		Minimum runaway length : 514.286

Q2. 두 점 (x1, y1), (x2, y2)를 입력받아 이 두 점 사이의 거리를 
	출력하는 프로그램을 작성하라.
	거리 계산 공식:
	QUARE ROOT ( ( x2 - x1 ) ^2 + (y2-y1) ^ 2)
	ex > x1, y1 : 1.5 -3.4
		 x2, y2 : 4    5
		 Distance : 8.7641

Q3. p.368 04.
	a. 회원 등록 -> 파일 저장
	b. 실명으로 열람 ( 파일 오픈 )
	...
	e. 회원이 지정한 것으로 열람 ( 파일 오픈 )
	q. 종료
*/

/*
// Q1.
int main()
{
	float speed, accelation, length;
	cout << " > Speed and Accelation : ";
	cin >> speed >> accelation;
	length = (speed * speed) / (2 * accelation);
	cout << "Minimum runaway length : " << length;
}
*/

/*
// Q2.
#include <math.h>
int main()
{
	float x1, x2, y1, y2, distance;
	cout << "두 점을 입력하세요.\n";
	cout << "> x1, y1: ";
	cin >> x1 >> y1;
	cout << "> x2, y2: ";
	cin >> x2 >> y2;

	distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

	cout << "Distance: " << distance << endl;
}
*/

/*
*/
// Q3.
#include <fstream>
#define strsize 256
#define MAX 20

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
} typedef Bop;


void addMember(Bop *bops, int* idx)		// 파일에 회원 추가하는 함수
{
	ofstream ofile;
	ofile.open("../data/bop.txt", ios::app);

	if (ofile.fail())
	{
		cout << "파일 읽기를 실패하여 종료합니다.\n";
		exit(0);
	}

	cin.get();

	cout << "실명 입력: ";
	cin.getline(bops[*idx].fullname, strsize);
	ofile << bops[*idx].fullname << endl;

	cout << "직함 입력: ";
	cin.getline(bops[*idx].title, strsize);
	ofile << bops[*idx].title << endl;

	cout << "BOP 아이디 입력: ";
	cin.getline(bops[*idx].bopname, strsize);
	ofile << bops[*idx].bopname << endl;

	cout << "나타낼 방식 입력(0: 실명, 1: 직함, 2: BOP): ";
	cin >> bops[*idx].preference;
	ofile << bops[*idx].preference << endl;


	(*idx)++;
	ofile.close();
}

void readFromFile(Bop* bops, int* idx)		// 파일에서 회원 목록 가져오는 함수
{
	ifstream ifile;
	char temp[3];
	ifile.open("../data/bop.txt");

	if (ifile.fail())
	{
		cout << "파일 읽기를 실패하여 종료합니다.\n";
		exit(0);
	}

	while (ifile.good())
	{
		ifile.getline(bops[*idx].fullname, strsize);
		ifile.getline(bops[*idx].title, strsize);
		ifile.getline(bops[*idx].bopname, strsize);
		ifile.getline(temp, 3);
		bops[*idx].preference = atoi(temp);
		//ifile >> bops[*idx].preference;	// 0, 1, 2의 값

		(*idx)++;
	}
	
	(*idx)--;
	ifile.close();
}

void printFullName(Bop* bops, int currentIdx)		// 성명으로 저장된 회원 정보 출력
{
	for (int i = 0; i < currentIdx; i++)
	{
		cout << bops[i].fullname << endl;
	}
}

void printTitle(Bop* bops, int currentIdx)			// 직함으로 저장된 회원 정보 출력
{
	for (int i = 0; i < currentIdx; i++)
	{
		cout << bops[i].title << endl;
	}
}

void printBopName(Bop* bops, int currentIdx)		// BOP ID로 저장된 회원 정보 출력
{
	for (int i = 0; i < currentIdx; i++)
	{
		cout << bops[i].bopname << endl;
	}
}

void printAllMember(Bop* bops, int currentIdx)		// 어떤 형식으로든 저장된 회원 정보 출력
{
	for (int i = 0; i < currentIdx; i++)
	{
		if (bops[i].preference == 0)
			cout << "#" << i + 1 << " Full Name: " << bops[i].fullname << endl;
		else if (bops[i].preference == 1)
			cout << "#" << i + 1 << " Title: " << bops[i].title << endl;
		else if (bops[i].preference == 2)
			cout << "#" << i + 1 << " BOP Name: " << bops[i].bopname << endl;
	}
}


int main()
{
	Bop bops[MAX] = {};
	int currentIdx = 0;
	char menu;
	
	readFromFile(bops, &currentIdx);


	while ( 1 ) 
	{
		cout << "\n메뉴를 선택하세요.\n\n";

		cout << "a. 회원 등록 (파일 저장)      b. 실명으로 열람\n"
			"c. 직함으로 열람              d. BOP 아이디로 열람  \n"
			"e. 회원이 지정한 것으로 열람  q. 종료\n\n";

		cout << "> ";
		cin >> menu;

		switch (menu)
		{
		case 'a':
			addMember(bops, &currentIdx);
			break;
		case 'b':
			printFullName(bops, currentIdx);
			break;
		case 'c':
			printTitle(bops, currentIdx);
			break;
		case 'd':
			printBopName(bops, currentIdx);
			break;
		case 'e':
			printAllMember(bops, currentIdx);
			break;
		case 'q':
			return 0;
			break;
		default:
			cout << "메뉴를 다시 확인하세요. \n\n";
			break;
		}
	}
}