#include<stdio.h>
#include<stdlib.h>
#include"Check_situations.h"
#include"Initialization.h"
#include"Input.h"
#include"Make_changes.h"
#include"Print_the_grid.h"
#define SIZE 8

int main()
{
	char grid[SIZE+5][SIZE+5];
	char color[4] = { '.','B','W' },input1,input2;
	char name[3][10] = { {""},{"Black"},{"White"} };
	int point[4], turn = 1, row = 0, column = 0;
	int winer;
	while (1)
	{
		Initialization(grid, point, &turn);
		while (check_possibility_of_new_move(1, grid) || check_possibility_of_new_move(2, grid))
		{
			print_grid(grid, point);
			if (!check_possibility_of_new_move(turn, grid))/*player can't move so turn changes*/
				turn = 3 - turn;
			printf("Player %d (%s) turn , Please choose a blank cell : ", turn,name[turn]);
			get_input(grid, turn, &row, &column);
			grid[row][column] = color[turn];
			point[turn]++;
			make_changes_of_new_move(grid, turn, row, column, point);
			turn = 3 - turn;/*change turn*/
		}
		print_grid(grid, point);
		winer = 2;
		if (point[1] > point[2])
			winer = 1;
		else if (point[1] == point[2])
			winer = 0;
		if (winer)
			printf("Player %d (%s) is winner !!!\n", winer,name[winer]);
		else
			printf("DRAW!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("Black : %d\nWhite : %d\n\n", point[1], point[2]);
		printf("Press number 1 and enter if you want to play again, other wise press any thing : ");
		input1 = getchar();
		if (input1 == '\n')
			break;
		input2 = getchar();
		if (input1 != '1' || input2 != '\n')
			break;
	}
	return 0;
}