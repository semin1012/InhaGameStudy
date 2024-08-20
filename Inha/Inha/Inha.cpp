#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StopWatch.h"
using namespace std;

/*
Q1. p.1343 문제 7.

 Q2. 용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는
   *  프로그램을 작성하라. 사용자로부터 소스 파일명을 입력 받은 후,
   *  각각 분할된 작은 파일의 바이트 값을 입력 받아야 한다.
   *
   *  ex > Enter file name : test.zip
   *       Enter fill size : 1024
   *       -> file test.zip.01
   *       -> file test.zip.02
   *       -> file test.zip.03
   *      .....
   *      >> Split Done

Q3. 사용자로부터 소스 파일의 개수, 소스 파일의 이름, 목적 파일의 이름을
	입력받아 새로운 하나의 파일로 파일들을 조합하는 프로그램을 작성하라.

	ex> Enter file number: 4
		Enter source number: file test.zip.01
		Enter source number: file test.zip.02
		Enter source number: file test.zip.03
		Enter source number: file test.zip.04
		Enter target file: Dest.zip
		....
			>> Combine Done.
*/

#include <fstream>
#include <filesystem>

char temp[32768];

void splitFile()
{
	string fileName;
	int fileSize;
	fstream finout;

	// Q2. 파일 분할
	cout << "파일 이름 입력: ";
	cin >> fileName;
	cout << "크기 입력(2-32,768):";
	cin >> fileSize;

	finout.open(fileName, ios_base::in | ios_base::out | ios_base::binary);


	if (!finout.is_open())
	{
		cout << "파일 읽기 실패!\n";
		exit(EXIT_FAILURE);
	}
	
	finout.seekg(ios_base::beg);

	int i = 1;
	while (!finout.eof())
	{
		char number[2];
		string saveName = fileName + '.' + itoa(i, number, 10);

		fstream out;
		out.open(saveName, ios_base::out | ios_base::binary);

		finout.read((char*)&temp, fileSize);

		out.write(temp, fileSize);

		cout << saveName << " 파일 생성\n";
		i++;

		out.close();
	}

	if (finout.eof())
		finout.clear();

	else
	{
		cout << "파일 읽다가 오류 발생\n";
		exit(EXIT_FAILURE);
	}

	finout.close();
}

void mergeFile()
{
	int fileNum;
	string inputName;
	string targetName;
	fstream saveTemp;

	cout << "Enter target file name: ";
	cin >> targetName;

	saveTemp.open(targetName, ios_base::binary | ios_base::out);

	if (!saveTemp.is_open())
	{
		cout << targetName << " 열기 실패\n";
		exit(EXIT_FAILURE);
	}


	cout << "Enter File Number: ";
	cin >> fileNum;

	for (int i = 0; i < fileNum; i++)
	{
		cout << "Enter source number: ";
		fstream fileTemp;
		cin >> inputName;
		fileTemp.open(inputName.c_str(), ios_base::binary | ios_base::in | ios_base::out);

		if (!fileTemp.is_open())
		{
			cout << inputName << " 열기 실패\n";
			exit(EXIT_FAILURE);
		}
		cout << inputName << " open success\n";


		fileTemp.seekg(0, ios::end);
		int length = fileTemp.tellg();
		fileTemp.seekg(0, ios::beg);

		while (fileTemp.read((char*)&temp, length))
		{
			saveTemp.write(temp, length);
		}
		fileTemp.close();
	}

	cout << "저장되었습니다.\n";
	saveTemp.close();
}

int main()
{
	splitFile();
	mergeFile();
}