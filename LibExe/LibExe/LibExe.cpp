﻿// LibExe.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#pragma comment(lib, "lib/LibTest.lib")
extern void lib_TextOut();

int main()
{
	lib_TextOut();
	return 0;
}