#include "Print_the_grid.h"
#define SIZE 8
void print_grid(char grid[SIZE + 5][SIZE + 5], int *point)
{
	system("cls");
	printf("OTHELLO GAME !!!!\nPlayer 1 : BLACK\nPlayer 2 : WHITE\n\n");
	int i, j;
	printf("    ");
	for (i = 1;i <= 8;i++)
		printf("%d  ", i);
	printf("PLayer 1 (Black)= %d *** Player 2 (White)= %d\n", point[1], point[2]);
	for (i = 1;i <= 8;i++)
	{
		for (j = 0;j <= 8;j++)
		{
			if (j == 0)
				printf("%d  ", i * 10);
			else
				printf("%c  ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}