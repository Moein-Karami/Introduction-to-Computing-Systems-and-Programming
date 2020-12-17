#include "Initialization.h"
#define SIZE 8
void Initialization(char grid[SIZE + 5][SIZE + 5], int *point, int* turn)
{
	*turn = 1;
	point[1] = 2;
	point[2] = 2;
	int row, column;
	for (row = 0;row <= SIZE + 1;row++)
	{
		for (column = 0;column <= SIZE + 1;column++)
		{
			if (row<1 || row>SIZE || column<0 || column>SIZE)
			{
				grid[row][column] = 'e';
			}
			else
				grid[row][column] = '.';
		}
	}
	grid[4][4] = 'W';
	grid[5][5] = 'W';
	grid[4][5] = 'B';
	grid[5][4] = 'B';
}