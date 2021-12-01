#include "CONST_VALUES_AND_LIBRARYS.h"
#include "Check_situations.h"
#include "Initialization.h"
#include "Input.h"
#include "Make_changes.h"
#include "Print_the_grid.h"
int main()
{
	char grid[MY_SIZE + 5][MY_SIZE + 5];
	char color[4] = { '.','B','W' }, input1, input2;
	char name[3][10] = { { "" },{ "Black" },{ "White" } };
	int point[4], turn = 1, row = 1, column = 1;
	int winer;
	int rect_x, rect_y;
	initwindow(660, 640, "OTHELLO");

	while (1)
	{
		Initialization(grid, point, &turn,&rect_x,&rect_y,&row,&column);
		while (check_possibility_of_new_move(1, grid) || check_possibility_of_new_move(2, grid))
		{
			print_grid(grid, point);
			if (!check_possibility_of_new_move(turn, grid))/*player can't move so turn changes*/
				turn = 3 - turn;
			get_input(grid, turn, &row, &column,&rect_x,&rect_y);
			make_changes_of_new_move(grid, turn, row, column, point);
			turn = 3 - turn;/*change turn*/
		}
		print_grid(grid, point);
		setbkcolor(CYAN);/*for show the winner*/
		settextstyle(COMPLEX_FONT, HORIZ_DIR, 30);
		setcolor(RED);
		winer = 2;
		if (point[1] > point[2])
		{
			winer = 1;
			outtextxy(45, 280, "BLACK WINS!");
		}
		else if (point[1] == point[2])
		{
			winer = 0;
			outtextxy(170, 280, "DRAW!!");
		}
		else
		{
			outtextxy(45, 280, "WHITE WINS!");
		}
		if (winer)
			printf("Player %d (%s) is winner !!!\n", winer, name[winer]);
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