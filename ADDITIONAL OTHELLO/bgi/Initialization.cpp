#include "CONST_VALUES_AND_LIBRARYS.h"
#include "draw.h"
void Initialization(char grid[MY_SIZE + 5][MY_SIZE + 5], int *point, int* turn, int* rect_x,int* rect_y, int* row, int* column)
{
	int x = 110, y = 110,i,j,k;
	int row_, column_;
	cleardevice();
	setfillstyle(SOLID_FILL,MY_DARK_BLUE);/*set screen black*/
	floodfill(110, 110, MAGENTA);
	*rect_x = 105;
	*rect_y = 105;
	setcolor(MY_BROWN);
	rectangle(40, 40, 600, 600);/*creat the frame*/
	rectangle(60, 60, 580, 580);
	setfillstyle(SOLID_FILL, MY_LIGHT_BLUE);
	floodfill(110, 110, MY_BROWN);
	setfillstyle(SOLID_FILL, MY_BROWN);
	floodfill(50, 50, MY_BROWN);
	/*creat empty circles*/
	setcolor(DARKGRAY);
	for (i = 0;i < 8;i++)
	{
		for (j = 0;j < 8;j++)
		{
			draw_circle(110 + i*MAIN_SIZE, 110 + j*MAIN_SIZE, DARKGRAY, 1);
		}
	}
	/*first four circles*/
	draw_circle(110 + 3*MAIN_SIZE, 110 + 3*MAIN_SIZE, WHITE, 1);
	draw_circle(110 + 4*MAIN_SIZE, 110 + 4*MAIN_SIZE, WHITE, 1);
	draw_circle(110 + 3*MAIN_SIZE, 110 + 4*MAIN_SIZE, BLACK, 1);
	draw_circle(110 + 4*MAIN_SIZE, 110 + 3*MAIN_SIZE, BLACK, 1);
	draw_rect(105,105,RED);/*creat red rectangle*/

	*row = 1;
	*column = 1;
	*turn = 1;
	point[1] = 2;
	point[2] = 2;

	for (row_ = 0;row_ <= MY_SIZE + 1;row_++)/*clean the grid(not graphic one)*/
	{
		for (column_= 0;column_ <= MY_SIZE + 1;column_++)
		{
			if (row_<1 || row_>MY_SIZE || column_<0 || column_>MY_SIZE)
			{
				grid[row_][column_] = 'e';
			}
			else
				grid[row_][column_] = '.';
		}
	}
	grid[4][4] = 'W';
	grid[5][5] = 'W';
	grid[4][5] = 'B';
	grid[5][4] = 'B';
}