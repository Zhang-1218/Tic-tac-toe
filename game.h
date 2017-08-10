#ifndef _GAME_H_
#define _GAME_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW  3
#define COL  3


void init_tic(char arr[ROW][COL], int row, int col);
void stamp_tic(char arr[ROW][COL], int row, int col);
void computer_move(char arr[ROW][COL], int row, int col);
void player_move(char arr[ROW][COL], int row, int col);
char judge_win(char arr[ROW][COL], int row, int col);
char is_full(char arr[ROW][COL], int row, int col);
char check_tic(char arr[ROW][COL], int row, int col);
char judge_tic(char arr[ROW][COL], int row, int col, int k);

#endif // _GAME_H_

