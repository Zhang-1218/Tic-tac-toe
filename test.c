#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char arr[ROW][COL];
	char ret = 0;
	init_tic(arr, ROW, COL);
	while (1)
	{
		stamp_tic(arr, ROW, COL);
		computer_move(arr, ROW, COL);
		if ((ret = judge_win(arr, ROW, COL)) != ' ')
			break;
		stamp_tic(arr, ROW, COL);
		player_move(arr, ROW, COL);
		if ((ret = judge_win(arr, ROW, COL)) != ' ')
			break;
	}
	stamp_tic(arr, ROW, COL);
	if ('X' == ret)  //返回X，表示玩家赢
	{
		printf("\n恭喜你，你赢啦！\n\n");
	}
	else if ('0' == ret)  //返回0，表示电脑赢
	{
		printf("\n呵呵，电脑赢了！\n\n");
	}
	else if ('Q' == ret)  //返回Q，表示平局
	{
		printf("\n平局哦！\n\n");
	}
}


void menu()   //menu为创建菜单函数
{
	printf("*****************************************************\n");
	printf("*****************     欢迎来到三子棋     ************\n");
	printf("********************     1. play     ****************\n");
	printf("********************     0. exit     ****************\n");
	printf("*****************************************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));//产生随机数
	do
	{
		menu();
		printf("\n请输入:<");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("输入错误!\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}