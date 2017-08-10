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
	if ('X' == ret)  //����X����ʾ���Ӯ
	{
		printf("\n��ϲ�㣬��Ӯ����\n\n");
	}
	else if ('0' == ret)  //����0����ʾ����Ӯ
	{
		printf("\n�Ǻǣ�����Ӯ�ˣ�\n\n");
	}
	else if ('Q' == ret)  //����Q����ʾƽ��
	{
		printf("\nƽ��Ŷ��\n\n");
	}
}


void menu()   //menuΪ�����˵�����
{
	printf("*****************************************************\n");
	printf("*****************     ��ӭ����������     ************\n");
	printf("********************     1. play     ****************\n");
	printf("********************     0. exit     ****************\n");
	printf("*****************************************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned)time(NULL));//���������
	do
	{
		menu();
		printf("\n������:<");
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
			printf("�������!\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}