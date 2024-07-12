#include <stdio.h>

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
//	fprintf(ofp, "%d", coinNum);
//
//	fclose(ofp);
//}

// Stage 2 
int main()
{
	system("mode con cols=120 lines=35 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	FILE* ofp;
	ofp = fopen("../data/map_2.txt", "wb");
	
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
			else if ((j == 8 || j == 16) && ( i % 2 != 0 ))
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if ((i == 8 || i == 16) && (j % 2 != 0))
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (i == j && i % 4 == 0)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (i == 24-j && i % 4 == 0)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (j == 12 && i % 4 == 0)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
			}
			else if (i == 12 && j % 4 == 0)
			{
				fprintf(ofp, "%d ", 1);
				printf("%d ", 1);
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
	fprintf(ofp, "%d", coinNum);
	printf("%d ", coinNum);

	fclose(ofp);
}