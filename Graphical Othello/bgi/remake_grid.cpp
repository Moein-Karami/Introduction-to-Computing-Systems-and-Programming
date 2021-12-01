#include "CONST_VALUES_AND_LIBRARYS.h"
#include "draw.h"
void remake_grid(char grid[MY_SIZE + 5][MY_SIZE + 5], int rect_x, int rect_y)
{
	int row, column, color;
	setfillstyle(SOLID_FILL, MY_LIGHT_BLUE);
	floodfill(65, 65, MY_BROWN);/*paint BLUE inside the frame */
	for (row = 0;row < MY_SIZE;row++)
	{
		for (column = 0;column < MY_SIZE;column++)
		{
			color = DARKGRAY;
			if (grid[row+1][column+1] == 'W')
				color = WHITE;
			else if (grid[row+1][column+1] == 'B')
				color = BLACK;
			draw_circle(110 + column*MAIN_SIZE, 110 + row*MAIN_SIZE, color, 0);/*remake circles*/
		}
	}
	draw_rect(rect_x, rect_y, RED);
}