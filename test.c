#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void game(void)
{
	int s;
	int i;
	int j;
	char t1[11][11];
	char t2[11][11];
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			t1[i][j] = '*';
		}
	}
	for (i = 0; i < 11; i++)
	{
		for (j = 0; j < 11; j++)
		{
			t2[i][j] = '0';
		}
	}
	srand((unsigned int)time(NULL));
	for (s = 0; s < 15; s++)
	{
		if (t2[rand() % 9 + 1][rand() % 9 + 1] == '0')
		{
			t2[rand() % 9 + 1][rand() % 9 + 1] = '1';
		}
	}
	for (s = 0; s < 10; s++)
	{
		printf("%d ", s);
	}
	printf("\n");
	for (i = 1; i < 10; i++)
	{
		printf("%d", i);
		for (j = 1; j < 10; j++)
		{
			printf(" %c", t1[i][j]);
		}
		printf("\n");
	}
	while (1)
	{
	angle:
		int count = 0;
		printf("请选择坐标:>");
		scanf("%d %d", &i, &j);
		if (i <= 9 && i >= 1 && j >= 1 && j <= 9)
		{
			if (t2[i][j] == '1')
			{
				printf("地雷炸了！\n");
				printf("游戏结束！");
				goto end;
			}
			else if (t1[i][j] == '*')
			{
				t1[i][j] = (t2[i - 1][j - 1] + t2[i - 1][j] + t2[i - 1][j + 1]
					+ t2[i][j - 1] + t2[i][j + 1] + t2[i + 1][j - 1]
					+ t2[i + 1][j] + t2[i + 1][j + 1]) - 8 * '0';
			}
			else
			{
				printf("非法输入！\n");
				goto angle;
			}
		}
		else
		{
			printf("非法输入！\n");
			goto angle;
		}
		for (i = 1; i < 10; i++)
		{
			for (j = 1; j < 10; j++)
			{
				if (t1[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count == 10)
		{
			printf("恭喜你！你赢了！");
			goto end;
		}
		for (s = 0; s < 10; s++)
		{
			printf("%d ", s);
		}
		printf("\n");
		for (i = 1; i < 10; i++)
		{
			printf("%d", i);
			for (j = 1; j < 10; j++)
			{
				if (t1[i][j] == '*')
				{
					printf(" %c", t1[i][j]);
				}
				else
				{
					printf(" %d", t1[i][j]);
				}
			}
			printf("\n");
		}
	}
end:;
}
int main(void)
{
	int a;
	printf("扫雷游戏 \n");
	printf("1.play\n");
	printf("0.exit\n");
	printf("请选择:>");
start:
	scanf("%d", &a);
	if (a == 1)
	{
		printf("游戏开始！\n");
		game();
	}
	else if (a == 0)
	{
		printf("退出游戏！");
	}
	else
	{
		printf("非法输入！\n");
		printf("请重新输入:>");
		goto start;
	}
	return 0;
}