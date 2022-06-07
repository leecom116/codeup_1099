
// 코드업 기초 1099번 문제

#include <stdio.h>

int main(void)
{
	int i, j;
	int a[10][10] = { 0 }; // 10*10 2차원 배열안에 모든 값 0으로 초기화
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	int x = 1;
	int y = 1;

	while (1)
	{
		if (a[1][1] == 2) // 시작점에 먹이가 있는 경우
		{
			a[x][y] = 9;
			break;
		}
		else if (a[x][y + 1] == 2) //오른쪽에 먹이가 있는 경우
		{
			a[x][y] = 9;
			a[x][y + 1] = 9;
			break;
		}
		else if (a[x + 1][y] == 1 && a[x][y + 1] == 1) 
		{ // 아래쪽과 오른쪽이 막힌 경우
			a[x][y] = 9;
			break;
		}
		else if (a[x][y + 1] == 0) // 오른쪽에 벽이 없는 경우
		{
			a[x][y] = 9;
			y++; // 오른쪽으로 한 칸 이동
		}
		else if (a[x + 1][y] == 2)
		{ // 아래쪽에 먹이가 있는 경우
			a[x][y] = 9;
			a[x + 1][y] = 9;
			break;
		}
		else if (a[x][y + 1] == 1)
		{ // 오른쪽에 벽이 있는 경우
			a[x][y] = 9;
			x++; // 아래쪽으로 한 칸 이동
		}
		
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			printf("%d ", a[i][j]); // 10*10 크기의 미로 상자 출력
		}
		printf("\n");
	}
	return 0;
}