#include "Make_changes.h"
#include "Check_situations.h"
#define SIZE 8

void make_changes_of_new_move(char grid[SIZE + 5][SIZE + 5], int turn, int row, int column, int *point)
{
	char color[] = { '.','B','W','.' };
	int i, j;
	int copy_row = row, copy_col = column;
	for (i = -1;i <= 1;i++)
	{
		for (j = -1;j <= 1;j++)
		{
			row = copy_row;
			column = copy_col;
			if (i == 0 && j == 0)
				continue;
			if (check_block(grid, turn, row, column, i, j))
			{
				while (grid[row + i][column + j] == color[3 - turn])
				{
					point[turn]++;
					point[3 - turn]--;
					grid[row + i][column + j] = color[turn];
					row += i;
					column += j;
				}
			}
		}
	}
}