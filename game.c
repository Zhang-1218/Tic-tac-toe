#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
  
void init_tic(char arr[ROW][COL],int row,int col) //��ʼ����������Ϊ�ո�
{
	memset(arr, ' ', row*col*sizeof(char));
}

void stamp_tic(char arr[ROW][COL], int row, int col) //��ӡ����
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

void player_move(char arr[ROW][COL], int row, int col) //����ƶ�
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("����ߣ�\n");
		printf("���������꣺<");
		scanf("%d%d", &x, &y); //���ѡ������
		printf("\n");
		if ((x > 0 && x <= 3) && (y > 0 && y <= 3)) //�ж����������Ƿ���ȷ������ȷ���ƶ�
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
				printf("�±��������������룺<");
			}
		}
		else
		{
			printf("�±��������������룺<");
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

char check_tic(char arr[ROW][COL], int row, int col) //�����ж��Ƿ����ʤ��
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


void computer_move(char arr[ROW][COL], int row, int col) //���Բ���������꣬�ƶ�
{
	int x = 0;
	int y = 0;
	int z = 0;
	printf("������!\n\n");
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

	//while (1)
	//{
	//	x = rand() % 3;   //���Բ����������
	//	y = rand() % 3;
	//	if (arr[x][y] == ' ')
	//	{
	//		arr[x][y] = '0';
	//		break;
	//	}
	//}

char is_full(char arr[ROW][COL], int row, int col) //�ж������Ƿ��Ѿ�����
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

char judge_win(char arr[ROW][COL], int row, int col) //�ж��Ƿ���ʤ��
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)  //�ж����Ƿ�������һ��
	{
		if ((arr[i][0] == arr[i][1]) 
			&& (arr[i][1] == arr[i][2]) 
			&& (arr[i][1] != ' '))
		{
			return arr[i][1];
		}
	}

	for (j = 0; j < col; j++)  //�ж����Ƿ�������һ��
	{
		if ((arr[0][j] == arr[1][j]) 
			&& (arr[1][j] == arr[2][j]) 
			&& (arr[1][j] != ' '))
		{
			return arr[1][j];
		}
	}

	if ((arr[0][0] == arr[1][1])  //�ж����Խ����Ƿ�����һ�� 
		&& (arr[1][1] == arr[2][2]) 
		&& (arr[1][1] != ' '))
		return arr[1][1];

	if ((arr[0][2] == arr[1][1]) //�ж�б�Խ����Ƿ�����һ��
		&& (arr[1][1] == arr[2][0]) 
		&& (arr[1][1] != ' '))
		return arr[1][1];

	if (is_full(arr, row, col))  //�ж��������Ƿ��пո�
	{
		return 'Q'; //����Q����ʾƽ��
	}
	return ' ';  //���ؿո񣬱�ʾ��Ϸ����
}
