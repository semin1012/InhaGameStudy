#include <stdio.h>

int main()
{
	system("mode con cols=120 lines=35 | title Coin Run"); // 콘솔창 크기 및 제목 설정
	FILE* ofp;
	ofp = fopen("../data/map_1.txt", "wb");

	if (ofp == NULL)
	{
		printf("읽기 실패!\n");
	}
	else printf("읽기 성공!\n");

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 60; j++) {
			if (i == 0 || i == 28)
				fprintf(ofp, "%d ", 1);
			else if (i % 4 == 0 && j % 5 != 0)
				fprintf(ofp, "%d ", 1);

			/*else if ( j % 4 == 0 )
				printf("%d ", 1);*/
			else if(j == 0 || j == 59)
				fprintf(ofp, "%d ", 1);
			else if (i % 2 == 0 && i % 4 != 0)
				fprintf(ofp, "%d ", 2);
			else fprintf(ofp, "%d ", 0);
		}
		fprintf(ofp, "\n");
	}

	fclose(ofp);
}