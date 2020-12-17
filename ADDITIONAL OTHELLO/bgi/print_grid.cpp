#include "CONST_VALUES_AND_LIBRARYS.h"
void print_grid(char grid[MY_SIZE + 5][MY_SIZE + 5], int *point)
{
	system("cls");
	printf("OTHELLO GAME !!!!\nPlayer 1 : BLACK\nPlayer 2 : WHITE\n\n");
	printf("PLayer 1 (Black)= %d *** Player 2 (White)= %d\n", point[1], point[2]);
	printf("\n\n");
}