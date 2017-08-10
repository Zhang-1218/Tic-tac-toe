#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
  
void init_tic(char arr[ROW][COL],int row,int col) //初始化数组内容为空格
{
	memset(arr, ' ', row*col*sizeof(char));
}

void stamp_tic(char arr[ROW][COL], int row, int col) //打印数组
{
	int i = 0;
	printf("-------------\n");
	
	for (i = 0; i < row; i++) 
	{
		printf("| %c | %c | %c |\n", arr[i][0], arr[i][1], arr[i][2]);
		if (i != 2)
		{
			printf("|---|---|---|\n");
		}
	}
	printf("-------------\n\n");
}

void player_move(char arr[ROW][COL], int row, int col) //玩家移动
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走！\n");
		printf("请输入坐标：<");
		scanf("%d%d", &x, &y); //玩家选择坐标
		printf("\n");
		
		if ((x > 0 && x <= 3) && (y > 0 && y <= 3)) //判断输入坐标是否正确，若正确则移动
		{
			x--;
			y--;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = 'X';
				break;
			}
			else
			{
				printf("下表有误，请重新输入：<");
			}
		}
		else
		{
			printf("下表有误，请重新输入：<");
		}
	}
}

char judge_tic(char arr[ROW][COL], int row, int col, int k)
{
	int i = 0;
	int j = 0;
	while (0 == k)
	{
		for (i = 0; i < row; i++)
		{
			if ((arr[i][0] == arr[i][1]) && (arr[i][1] == 'X') && (arr[i][2] == ' '))
			{
				arr[i][2] = '0';
				k = 1;
				break;
			}

			if ((arr[i][0] == arr[i][2]) && (arr[i][0] == 'X') && (arr[i][1] == ' '))
			{
				arr[i][1] = '0';
				k = 1;
				break;
			}

			if ((arr[i][1] == arr[i][2]) && (arr[i][1] == 'X') && (arr[i][0] == ' '))
			{
				arr[i][0] = '0';
				k = 1;
				break;
			}
		}
		if (k != 0)
			break;
		for (j = 0; j < col; j++)
		{
			if ((arr[0][j] == arr[1][j]) && (arr[1][j] == 'X') && (arr[2][j] == ' '))
			{
				arr[2][j] = '0';
				k = 1;
				break;
			}

			if ((arr[0][j] == arr[2][j]) && (arr[2][j] == 'X') && (arr[1][j] == ' '))
			{
				arr[1][j] = '0';
				k = 1;
				break;
			}

			if ((arr[1][j] == arr[2][j]) && (arr[2][j] == 'X') && (arr[0][j] == ' '))
			{
				arr[0][j] = '0';
				k = 1;
				break;
			}
		}
		break;
	}
	while (0 == k)
	{
		if ((arr[0][0] == arr[1][1]) && (arr[1][1] == 'X') && (arr[2][2] == ' '))
		{
			arr[2][2] = '0';
			k = 1;
			break;
		}
		
		if ((arr[0][0] == arr[2][2]) && (arr[2][2] == 'X') && (arr[1][1] == ' '))
		{
			arr[1][1] = '0';
			k = 1;
			break;
		}
		
		if ((arr[1][1] == arr[2][2]) && (arr[1][1] == 'X') && (arr[0][0] == ' '))
		{
			arr[0][0] = '0';
			k = 1;
			break;
		}
		
		if ((arr[0][2] == arr[1][1]) && (arr[0][2] == 'X') && (arr[2][0] == ' '))
		{
			arr[2][0] = '0';
			k = 1;
			break;
		}
		
		if ((arr[0][2] == arr[2][0]) && (arr[2][0] == 'X') && (arr[1][1] == ' '))
		{
			arr[1][1] = '0';
			k = 1;
			break;
		}
		
		if ((arr[1][1] == arr[2][0]) && (arr[2][0] == 'X') && (arr[0][2] == ' '))
		{
			arr[0][2] = '0';
			k = 1;
			break;
		}
		break;
	}
	return k;
}

char check_tic(char arr[ROW][COL], int row, int col) //电脑判断是否可以胜出
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (0 == k)
	{
		for (i = 0; i < row; i++)
		{
			if ((arr[i][0] == arr[i][1]) && (arr[i][1] == '0') && (arr[i][2] == ' '))
			{
				arr[i][2] = '0';
				k = 1;
				break;
			}

			if ((arr[i][0] == arr[i][2]) && (arr[i][0] == '0') && (arr[i][1] == ' '))
			{
				arr[i][1] = '0';
				k = 1;
				break;
			}

			if ((arr[i][1] == arr[i][2]) && (arr[i][1] == '0') && (arr[i][0] == ' '))
			{
				arr[i][0] = '0';
				k = 1;
				break;
			}
		}
		if (k != 0)
			break;
		for (j = 0; j < col; j++)
		{
			if ((arr[0][j] == arr[1][j]) && (arr[1][j] == '0') && (arr[2][j] == ' '))
			{
				arr[2][j] = '0';
				k = 1;
				break;
			}

			if ((arr[0][j] == arr[2][j]) && (arr[2][j] == '0') && (arr[1][j] == ' '))
			{
				arr[1][j] = '0';
				k = 1;
				break;
			}

			if ((arr[1][j] == arr[2][j]) && (arr[2][j] == '0') && (arr[0][j] == ' '))
			{
				arr[0][j] = '0';
				k = 1;
				break;
			}
		}
		break;
	}
	while (0 == k)
	{
		if ((arr[0][0] == arr[1][1]) && (arr[1][1] == '0') && (arr[2][2] == ' '))
		{
			arr[2][2] = '0';
			k = 1;
			break;
		}
		
		if ((arr[0][0] == arr[2][2]) && (arr[2][2] == '0') && (arr[1][1] == ' '))
		{
			arr[1][1] = '0';
			k = 1;
			break;
		}
		
		if ((arr[1][1] == arr[2][2]) && (arr[1][1] == '0') && (arr[0][0] == ' '))
		{
			arr[0][0] = '0';
			k = 1;
			break;
		}
		if ((arr[0][2] == arr[1][1]) && (arr[0][2] == '0') && (arr[2][0] == ' '))
		{
			arr[2][0] = '0';
			k = 1;
			break;
		}
		
		if ((arr[0][2] == arr[2][0]) && (arr[2][0] == '0') && (arr[1][1] == ' '))
		{
			arr[1][1] = '0';
			k = 1;
			break;
		}
		
		if ((arr[1][1] == arr[2][0]) && (arr[2][0] == '0') && (arr[0][2] == ' '))
		{
			arr[0][2] = '0';
			k = 1;
			break;
		}
		break;
	}
	k = judge_tic(arr, row, col, k);
	return k;
}


void computer_move(char arr[ROW][COL], int row, int col) //电脑产生随机坐标，移动
{
	int x = 0;
	int y = 0;
	int z = 0;
	printf("电脑走!\n\n");
	z = check_tic(arr, row, col);
	
	while (0 == z)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '0';
			z = 1;
			break;
		}
	}
}



char is_full(char arr[ROW][COL], int row, int col) //判断棋盘是否已经下满
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char judge_win(char arr[ROW][COL], int row, int col) //判断是否有胜出
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)  //判断行是否有三个一致
	{
		if ((arr[i][0] == arr[i][1]) 
			&& (arr[i][1] == arr[i][2]) 
			&& (arr[i][1] != ' '))
		{
			return arr[i][1];
		}
	}

	for (j = 0; j < col; j++)  //判断列是否有三个一致
	{
		if ((arr[0][j] == arr[1][j]) 
			&& (arr[1][j] == arr[2][j]) 
			&& (arr[1][j] != ' '))
		{
			return arr[1][j];
		}
	}

	if ((arr[0][0] == arr[1][1])  //判断正对角线是否三个一致 
		&& (arr[1][1] == arr[2][2]) 
		&& (arr[1][1] != ' '))
		return arr[1][1];

	if ((arr[0][2] == arr[1][1]) //判断斜对角线是否三个一致
		&& (arr[1][1] == arr[2][0]) 
		&& (arr[1][1] != ' '))
		return arr[1][1];

	if (is_full(arr, row, col))  //判断棋盘上是否还有空格
	{
		return 'Q'; //返回Q，表示平局
	}
	return ' ';  //返回空格，表示游戏继续
}
