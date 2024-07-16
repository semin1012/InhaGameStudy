#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// Stage 1
//int main()
//{
//	system("mode con cols=120 lines=35 | title Coin Run"); // 콘솔창 크기 및 제목 설정
//	FILE* ofp;
//	ofp = fopen("../data/map_1.txt", "wb");
//	
//	int coinNum = 0;
//
//	if (ofp == NULL)
//	{
//		printf("읽기 실패!\n");
//	}
//	else printf("읽기 성공!\n");
//
//	for (int i = 0; i < 25; i++) {
//		for (int j = 0; j < 25; j++) {
//			if (i == 0 || i == 24)
//				fprintf(ofp, "%d ", 1);
//			else if (i % 4 == 0 && j % 5 != 0)
//				fprintf(ofp, "%d ", 1);
//
//			/*else if ( j % 4 == 0 )
//				printf("%d ", 1);*/
//			else if(j == 0 || j == 24)
//				fprintf(ofp, "%d ", 1);
//			else if (i % 2 == 0 && i % 4 != 0) {
//				fprintf(ofp, "%d ", 2);
//				coinNum++;
//			}
//			else fprintf(ofp, "%d ", 0);
//		}
//		fprintf(ofp, "\n");
//	}
//	// 총 코인 개수 
//	fprintf(ofp, "%d ", coinNum);
//
//	// 플레이어 좌표 (x, y)
//	fprintf(ofp, "%d %d ", 20, 20);
//
//	// 몬스터 좌표 (x, y)
//	fprintf(ofp, "%d %d ", 1, 1);
//
//	// Enemy Speed
//	fprintf(ofp, "%d ", 3);
//	printf("%d ", 3);
//
//	// Enemy Num
//	fprintf(ofp, "%d ", 1);
//
//	// Enemys Pos
//	fprintf(ofp, "%d %d ", 1, 1);
//
//
//	fclose(ofp);
//}

// Stage 2 
//int main()
//{
//	system("mode con cols=120 lines=35 | title Coin Run"); // 콘솔창 크기 및 제목 설정
//	FILE* ofp;
//	ofp = fopen("../data/map_2.txt", "wb");
//	
//	int coinNum = 0;
//
//	if (ofp == NULL)
//	{
//		printf("읽기 실패!\n");
//		return 0;
//	}
//	else printf("읽기 성공!\n");
//
//	for (int i = 0; i < 25; i++) {
//		for (int j = 0; j < 25; j++) {
//			if (i == 0 || i == 24 || j == 0 || j == 24)
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if ((j == 8 || j == 16) && ( i % 2 != 0 ))
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if ((i == 8 || i == 16) && (j % 2 != 0))
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if (i == j && i % 4 == 0)
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if (i == 24-j && i % 4 == 0)
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if (j == 12 && i % 4 == 0)
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else if (i == 12 && j % 4 == 0)
//			{
//				fprintf(ofp, "%d ", 1);
//				printf("%d ", 1);
//			}
//			else
//			{
//				fprintf(ofp, "%d ", 2);
//				printf("%d ", 2);
//				coinNum++;
//			}
//		}
//		fprintf(ofp, "\n");
//		printf("\n");
//	}
//
//	// 총 코인 개수
//	fprintf(ofp, "%d ", coinNum);
//	printf("%d ", coinNum);
//
//	// 플레이어 좌표 (x, y)
//	fprintf(ofp, "%d %d ", 13, 20);
//	printf("%d %d ", 13, 20);
//
//	// 몬스터 좌표 (x, y)
//	fprintf(ofp, "%d %d ", 10, 12);
//	printf("%d %d ", 10, 12);
//
//	// Enemy Speed
//	fprintf(ofp, "%d ", 3);
//	printf("%d ", 3);
//
//	// Enemy Num
//	fprintf(ofp, "%d ", 1);
//	printf("%d\n", 2);
//
//	// Enemys Pos
//	fprintf(ofp, "%d %d ", 3, 2);
//	printf("%d %d\n", 3, 2);
//	//fprintf(ofp, "%d %d ", 20, 22);
//	//printf("%d %d\n", 20, 22);
//
//	fclose(ofp);
//}

// 스테이지 3
int main()
{
	system("mode con cols=120 lines=35 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	FILE* ofp;
	ofp = fopen("../data/map_3.txt", "wb");

	
	int coinNum = 0;

	if (ofp == NULL)
	{
		printf("읽기 실패!\n");
		return 0;
	}
	else printf("읽기 성공!\n");

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (i == 0 || i == 24 || j == 0 || j == 24)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (i == 5 && j <= 6 || i == 5 && j >= 17)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (i == 18 && j <= 6 || i == 18 && j >= 17)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			//else if (j == 11 && i > 5 && !(i > 17))
			//{
			//	fprintf(ofp, "%d ", 1);
			//	printf("%d ", 1);
			//}
			//else if (i == 11 && j > 6 && i == 11 && j < 17 )
			//{
			//	fprintf(ofp, "%d ", 1);
			//	printf("%d ", 1);
			//}
			else if (i == 1 || i == 23 || j == 1 || j == 23)
			{
				fprintf(ofp, "%d ", 0);
				printf("%d ", 0);
			}
			else if (i >= 7 && i <= 16 && j >= 7 && j <= 16 )
			{
				fprintf(ofp, "%d ", 0);
				printf("%d ", 0);
			}
			else
			{
				fprintf(ofp, "%d ", 2);
				printf("%d ", 2);
				coinNum++;
			}
		}
		fprintf(ofp, "\n");
		printf("\n");
	}

	// 총 코인 개수
	fprintf(ofp, "%d ", coinNum);
	printf("%d ", coinNum);

	// 플레이어 좌표 (x, y)
	fprintf(ofp, "%d %d ", 23, 23);
	printf("%d %d ", 23, 23);

	// 몬스터 좌표 (x, y)
	fprintf(ofp, "%d %d ", 1, 1);
	printf("%d %d ", 1, 1);

	// Enemy Speed
	fprintf(ofp, "%d ", 2);
	printf("%d ", 2);
	
	printf("\n");

	// 몬스터 수
	fprintf(ofp, "%d ", 2);
	printf("%d \n", 2);

	// 몬스터 좌표
	fprintf(ofp, "%d %d ", 5, 3);
	printf("%d %d\n", 5, 3);
	fprintf(ofp, "%d %d ", 20, 3);
	printf("%d %d\n", 20, 3);
	/*fprintf(ofp, "%d %d ", 5, 20);
	printf("%d %d\n", 5, 20);*/
	//fprintf(ofp, "%d %d ", 20, 20);
	//printf("%d %d ", 20, 20);

	fclose(ofp);
}