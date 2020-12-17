#include "CONST_VALUES_AND_LIBRARYS.h"
#include "input.h"
#include "Check_situations.h"
#include "draw.h"
void get_input(char grid[MY_SIZE + 5][MY_SIZE + 5], int turn, int* row, int* column,int* rect_x,int *rect_y)
{
	char name[3][10] = { { "" },{ "Black" },{ "White" } };
	char input;
	int wrong_input=0;
	int cnt = -1;

	int first_color, final_color;/*color of beginnig circle and final circle for red rectangle*/
	final_color = DARKGRAY;
	if (grid[*row][*column] == 'W')
		final_color = WHITE;
	else if (grid[*row][*column] == 'B')
		final_color = BLACK;

	printf("Player %d (%s) turn , Please choose a blank cell : ", turn, name[turn]);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	setcolor(WHITE);
	setbkcolor(MY_DARK_BLUE);
	if (turn == 1)/*show the turn in graphic screen*/
		outtextxy(245, 20, "BLACK'S TURN");
	else
		outtextxy(245, 20, "WHITE'S TURN");

	setbkcolor(CYAN);/*for show the wrong massage*/
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 30);
	setcolor(RED);
	while (1)
	{
		first_color = final_color;/*final color in last level is begining color now*/
		if (check_possibility_of_cell(grid, turn, *row, *column))
			draw_rect(*rect_x, *rect_y, GREEN);
		setcolor(RED);
		input = getchar();
		if (input != '\n')
		{
			if (getchar() != '\n')
			{
				while (getchar() != '\n');
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
		}
		if(wrong_input)/*the last move was wrong*/
			remake_grid(grid, *rect_x, *rect_y);
		if (input == '\n')/*press enter*/
		{
			wrong_input = 0;
			continue;
		}
		if (input == 'w')
		{
			if (*row == 1)/*out of grid*/
			{
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
			wrong_input = 0;
			(*row)--;
			final_color = DARKGRAY;
			if (grid[*row][*column] == 'W')
				final_color = WHITE;
			else if (grid[*row][*column] == 'B')
				final_color = BLACK;
			move_rect(*rect_x, *rect_y, *rect_x , *rect_y - MAIN_SIZE , first_color, final_color);
			*rect_y -= MAIN_SIZE;
		}
		else if (input == 's')
		{
			if (*row == 8)/*out of grid*/
			{
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
			wrong_input = 0;
			(*row)++;
			final_color = DARKGRAY;
			if (grid[*row][*column] == 'W')
				final_color = WHITE;
			else if (grid[*row][*column] == 'B')
				final_color = BLACK;
			move_rect(*rect_x, *rect_y, *rect_x, *rect_y + MAIN_SIZE, first_color, final_color);
			*rect_y += MAIN_SIZE;
		}
		else if (input == 'a')
		{
			if (*column == 1)/*out of grid*/
			{
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
			wrong_input = 0;
			(*column)--;
			final_color = DARKGRAY;
			if (grid[*row][*column] == 'W')
				final_color = WHITE;
			else if (grid[*row][*column] == 'B')
				final_color = BLACK;
			move_rect(*rect_x , *rect_y, *rect_x-MAIN_SIZE, *rect_y , first_color, final_color);
			*rect_x -= MAIN_SIZE;
		}
		else if (input == 'd')
		{
			if (*column == 8)/*out of grid*/
			{
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
			wrong_input = 0;
			(*column)++;
			final_color = DARKGRAY;
			if (grid[*row][*column] == 'W')
				final_color = WHITE;
			else if (grid[*row][*column] == 'B')
				final_color = BLACK;
			move_rect(*rect_x , *rect_y, *rect_x + MAIN_SIZE, *rect_y,first_color,final_color);
			*rect_x += MAIN_SIZE;
		}
		else if (input == 32)/*enter space*/
		{
			if (grid[*row][*column] != '.' || check_possibility_of_cell(grid, turn, *row, *column) == 0)
			{
				printf("\nWrong move. Please try again : ");
				outtextxy(170, 280, "WRONG!");
				wrong_input = 1;
				continue;
			}
			wrong_input = 0;
			return;
		}
		else/*unrelated input*/
		{
			printf("\nWRONG move. Please try again :");
			outtextxy(170, 280, "WRONG!");
			wrong_input = 1;
			continue;
		}
	}
}