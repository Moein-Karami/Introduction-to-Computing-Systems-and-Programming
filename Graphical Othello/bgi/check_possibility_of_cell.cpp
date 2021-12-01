#include "CONST_VALUES_AND_LIBRARYS.h"
#include "Check_situations.h"
int check_possibility_of_cell(char grid[MY_SIZE + 5][MY_SIZE + 5], int turn, int row, int column)/*barresi mohasereye mohre dar yek khane*/
{
	int row_change, col_change;
	if (grid[row][column] != '.')/*the cell is not empty*/
		return 0;
	for (row_change = -1;row_change <= 1;row_change++)
	{
		for (col_change = -1; col_change <= 1; col_change++)
		{
			if (row_change == 0 && col_change == 0)
				continue;
			if (check_block(grid, turn, row, column, row_change, col_change))/*aya in khane dar in jahat khas harif ra mohasere mikonad ?*/
				return 1;
		}
	}
	return 0;
}