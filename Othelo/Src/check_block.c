#include "Check_situations.h"
#define SIZE 8
int check_block(char grid[SIZE + 5][SIZE + 5], int turn, int row, int column, int row_change, int col_change)/*barresi mohasereye mohre dar yek khane va yek jahat khas*/
{
	char color[4] = { '.','B','W' };
	row += row_change;
	column += col_change;
	if (grid[row][column] != color[3 - turn])
		return 0;
	while (1)
	{
		row += row_change;
		column += col_change;
		if (grid[row][column] == color[turn])
			return 1;
		else if (grid[row][column] != color[3 - turn])
			return 0;
	}
	return 0;
}