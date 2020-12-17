#include "CONST_VALUES_AND_LIBRARYS.h"
#include "Check_situations.h"
#include "draw.h"
void make_changes_of_new_move(char grid[MY_SIZE + 5][MY_SIZE + 5], int turn, int row, int column, int *point)
{
	char color[] = { '.','B','W','.' };
	int i, j;
	int copy_row = row, copy_col = column;
	int circle_color = WHITE;
	if (turn == 1)
		circle_color = BLACK;
	grid[row][column] = color[turn];
	point[turn]++;
	draw_circle(110 + (column - 1)*MAIN_SIZE, 110 + (row - 1)*MAIN_SIZE, circle_color, 1);/*change color of choosen circle*/
	draw_rect(110 + (column - 1)*MAIN_SIZE - RECT_SIZE / 2, 110 + (row - 1)*MAIN_SIZE - RECT_SIZE / 2,RED);
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
					row += i;
					column += j;
					grid[row ][column ] = color[turn];
					draw_circle(110 + (column - 1)*MAIN_SIZE, 110 + (row - 1)*MAIN_SIZE, circle_color, 10);/*change surrendered circles*/
				}
			}
		}
	}
}