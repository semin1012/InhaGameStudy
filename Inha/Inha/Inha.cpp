#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "StopWatch.h"
using namespace std;

/*
Q1. Encoding
	파일 내의 모든 바이트에 임의 수를 더해 파일을 부호화하라.
	사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
	입력 파일의 암호화된 버전을 출력 파일로 저장하는 프로그램을
	작성하라.
	ex> Input source filename: source.txt
		Input encoding filename: encoding.txt
	encoding.txt에는 더한 임의 수를 알아볼 수 있도록 정보를 
	기입해준다. 

Q2. Decoding
	암호화된 파일을 복호화하는 프로그램을 작성하라.
	사용자가 입력 파일 이름과 출력 파일 이름을 입력하면
	입력 파일의 암호가 풀린 버전을 출력 파일에 저장하라.
	ex> Input source filename: encoding.txt
		Input decoding filename: dest.txt
	더해진 임의 수에 대한 정보를 읽어서 decoding 하도록 한다. 
*/

void Encoding(int num)
{
	string sourceFileName;
	string encodingFileName;
	char temp;

	cout << "Input source filename: ";
	cin >> sourceFileName;

	cout << "Input encoding filename: ";
	cin >> encodingFileName;

	ifstream inputFile(sourceFileName, ifstream::binary);
	ofstream outfutFile(encodingFileName, ofstream::binary);
	if (!inputFile.is_open())
	{
		cout << sourceFileName << " 열기 실패\n";
		exit(EXIT_FAILURE);
	}

	if (!outfutFile.is_open())
	{
		cout << encodingFileName << " 열기 실패\n";
		exit(EXIT_FAILURE);
	}

	// 암호화 숫자 넣기
	outfutFile << num << '\n';

	while(inputFile.read(&temp, 1))
	{
		temp += num;
		outfutFile.write(&temp, 1);
	}

	cout << encodingFileName << "에 " << num << "이 더해졌습니다.\n";
}

void Decoding()
{
	string sourceFileName;
	string decodingFileName;
	char temp;
	int num;
	string numTemp;

	cout << "Input source filename: ";
	cin >> sourceFileName;

	cout << "Input decoding filename: ";
	cin >> decodingFileName;

	ifstream inputFile(sourceFileName, ifstream::binary);
	ofstream outfutFile(decodingFileName, ofstream::binary);
	//inputFile.open(sourceFileName, ifstream::in | ifstream::binary);
	if (!inputFile.is_open())
	{
		cout << sourceFileName << " 열기 실패\n";
		exit(EXIT_FAILURE);
	}

	//outfutFile.open(decodingFileName, ios_base::out | ios_base::binary);
	if (!outfutFile.is_open())
	{
		cout << decodingFileName << " 열기 실패\n";
		exit(EXIT_FAILURE);
	}

	// 암호화 숫자 얻기
	getline(inputFile, numTemp);
	num = atoi(numTemp.c_str());

	while(inputFile.read(&temp, 1))
	{
		temp -= num;
		outfutFile.write(&temp, 1);
	}

	cout << sourceFileName << "이 " << decodingFileName << "에 복호화되었습니다.\n";
}

int main()
{
	Encoding(5);
	Decoding();
}