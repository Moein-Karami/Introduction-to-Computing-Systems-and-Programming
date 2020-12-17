#include <stdio.h>

void print_first_grid()
{
	printf("\n***** Alamat nafar aval : X *****\n");
	printf("***** Alamat nafar dovom : O *****\n");
	printf("\n");
	printf("     |     |     \n");
	printf("  7  |  8  |  9  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  4  |  5  |  6  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  1  |  2  |  3  \n");
	printf("     |     |     \n");
	printf("\n");
}
void clean_grid(char *cell,int  *turn,int  *moves)
{
	for (int i = 1;i <= 9;i++)
		cell[i] = ' ';
	*turn = 1;
	*moves = 0;
}
int get_input(char *cell,int turn)
{
	int number_of_chars,chosen_cell;
	char new_move,first_in;
	printf("Player %d's turn:\n", turn);
	printf("Please choose a number between 1 to 9 : ");
	while (1)
	{
		number_of_chars = 0;
		new_move = 's';
		while (new_move != '\n')
		{
			number_of_chars++;
			scanf_s("%c", &new_move);
			if (number_of_chars == 1)
				first_in = new_move;
			/*chon momken ast karbar ghabl az ragham khod 0 ya space bezand in do mored ra agar dar ebtedaye voroodi boodand hazf mikonim*/
			if ((number_of_chars == 1) && ((new_move == '0') || (new_move == ' ')))
				number_of_chars--;
		}
		chosen_cell = first_in - '0';
		if (number_of_chars != 2 || chosen_cell > 9 || chosen_cell < 1 || cell[chosen_cell] != ' ')
			printf("Your move is not correct! Please try again and insert a number between 1 to 9 :\n");
		else
			return chosen_cell;
	}
}
void print_grid(char *cell)
{
	printf("\n");
	printf("     |     |   \n");
	printf("  %c  |  %c  |  %c\n", cell[7], cell[8], cell[9]);
	printf("_____|_____|_____\n");
	printf("     |     |   \n");
	printf("  %c  |  %c  |  %c\n", cell[4], cell[5], cell[6]);
	printf("_____|_____|_____\n");
	printf("     |     |   \n");
	printf("  %c  |  %c  |  %c\n", cell[1], cell[2], cell[3]);
	printf("     |     |     \n");
	printf("\n");
}
int check_end_of_game(char *cell, int *moves, int *turn)
{
	char new_move;
	int i;
	int end = 0;
	for (int i = 1;i <= 3;i++)
		if (cell[i] != ' ')
			if (cell[i] == cell[i + 3] && cell[i] == cell[i + 6])
				end = 1;
	for (int i = 1;i <= 7;i += 3)
		if (cell[i] != ' ')
			if (cell[i] == cell[i + 1] && cell[i] == cell[i + 2])
				end = 1;
	if (cell[5] != ' ')
	{
		if (cell[5] == cell[7] && cell[5] == cell[3])
			end = 1;
		if (cell[5] == cell[9] && cell[5] == cell[1])
			end = 1;
	}
	if (end)
	{
		printf("Congratulations !\n");
		printf("Player %d has won the game!\n",3-*turn);
	}
	else if (*moves == 9)
	{
		printf("The game is over!\nNo one has won the game.\n");
		end = 1;
	}
	if (end)
	{
		clean_grid(cell, turn, moves);
		printf("Press number 1 and enter if you want to start a new game. Otherwise press any key.\n");
		scanf_s("%c", &new_move);
		if (new_move == '\n')
			return 0;
		getchar();
		if (new_move == '1')
		{
			print_first_grid();
			return 1;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	char cell[12];
	char symbol[5] = { ' ','X','O' };
	int turn, gaming=1,moves,new_move;
	clean_grid(cell, &turn, &moves);/*First situation of game*/
	print_first_grid();
	while (gaming == 1)
	{
		new_move = get_input(cell,turn);
		cell[new_move] = symbol[turn];/*change chosen cell*/
		turn = 3 - turn;/*change turn*/
		moves++;
		print_grid(cell);
		gaming = check_end_of_game(cell, &moves, &turn);
	}
	return 0;
}