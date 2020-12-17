#include "input.h"
#include "Check_situations.h"
#define SIZE 8

void get_input(char grid[SIZE + 5][SIZE + 5], int turn, int* row, int* column)
{
	char input[100];
	int cnt = -1;
	while (1)
	{
		do
		{
			cnt++;
			input[cnt] = getchar();
		} while (cnt < 99 && input[cnt] != '\n');
		if (cnt != 2)
		{
			printf("Your input is not correct. Please try again : ");
			cnt = -1;
			continue;
		}
		cnt = -1;
		*row = input[0] - '0';
		*column = input[1] - '0';
		if (*row < 1 || *row>8 || *column < 1 || *column>8)/*kharej jadval*/
			printf("Your input is not correct. Please try again : ");
		else if (grid[*row][*column] != '.')
			printf("Your chosen cell is not empty. Please try again : ");
		else if (check_possibility_of_cell(grid, turn, *row, *column) == 0)
			printf("Your input is not correct. Please try again : ");
		else
			return;
	}
}