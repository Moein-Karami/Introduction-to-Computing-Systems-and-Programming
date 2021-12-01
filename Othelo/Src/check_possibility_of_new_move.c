#include "Check_situations.h"
#define SIZE 8

int check_possibility_of_new_move(int turn, char grid[SIZE + 5][SIZE + 5])/*barresi tavanayi harkat player dar kol jadval*/
{
	int row = 0, column = 0;
	for (row = 1;row <= 8;row++)
	{
		for (column = 1;column <= 8;column++)
		{
			if (grid[row][column] == '.')
			{
				if (check_possibility_of_cell(grid, turn, row, column))/*aya in khane harif ra mohasere mikonad ?*/
					return 1;
			}
		}
	}
	return 0;
}