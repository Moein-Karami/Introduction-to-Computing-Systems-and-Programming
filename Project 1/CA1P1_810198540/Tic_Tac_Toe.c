#include<stdio.h>

int main()
{
	int end = 0, correctMove, numberOfChars;
	int turn = 1, moves = 0, gaming = 1;
	char c1 = ' ', c2 = ' ', c3 = ' ', c4 = ' ', c5 = ' ', c6 = ' ', c7 = ' ', c8 = ' ', c9 = ' ';/*character khane haye 1 ta 9*/
	char newMove, firstIn;
	printf("***** Dar tool bazi bad az vared kardan voroody enter ra bezanid*****\n\n");
	printf("***** Alamat nafar aval : X *****\n");
	printf("***** Alamat nafar dovom : O *****\n");
	printf("\n");
	printf("     |     |     \n");
	printf("  1  |  2  |  3  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  4  |  5  |  6  \n");
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  7  |  8  |  9  \n");
	printf("     |     |     \n");
	printf("\n");
	while (gaming==1)
	{
		/*Barresi payan bazi*/
		if (c1 != ' ')
		{ /*halati ke yeki az se khane yekjoor c1 bashad*/
			if ((c1 == c2) && (c1 == c3))
			{
				end = 1;
			}
			if ((c1 == c4) && (c1 == c7))
			{
				end = 1;
			}
			if ((c1 == c5) && (c1 == c9))
			{
				end = 1;
			}
		}
		if(c5 != ' ' )
		{/*halati ke yeki az se khane yekjoor c5 bashad*/
			if ((c5 == c2) && (c5 == c8))
			{
				end = 1;
			}
			if ((c5 == c4) && (c5 == c6))
			{
				end = 1;
			}
			if ((c5 == c3) && (c5 == c7))
			{
				end = 1;
			}
		}
		if(c9 != ' ')
		{/*halati ke yeki az se khane yekjoor c9 bashad*/
			if ((c9 == c3) && (c9 == c6))
			{
				end = 1;
			}
			if ((c9 == c8) && (c9 == c7))
			{
				end = 1;
			}
		}
		if ((moves == 9) || (end))
		{
			if (!end)/*bazi dar in halat mosavi ast chon 9 harkat anjam shode va barande nadarim*/
			{
				printf("The game is over!\nNo one has won the game.\n");
			}
			else
			{
				printf("Congratulations !\n");
				if (turn == 2)
				{
					printf("Player one has won the game!\n");
				}
				else
				{
					printf("Player two has won the game!\n");
				}
			}
			/*bargardandan bazi be halat aval darsoorat bazi dobare*/
			moves = 0;
			turn = 1;
			end = 0;
			c1 = ' ';
			c2 = ' ';
			c3 = ' ';
			c4 = ' ';
			c5 = ' ';
			c6 = ' ';
			c7 = ' ';
			c8 = ' ';
			c9 = ' ';

			printf("Press number 1 and enter if you want to start a new game. Otherwise press any key.\n");
			gaming = 0;
			scanf_s("%c", &newMove);
			if (newMove == '1')
				gaming = 1;
			/*agar karbar 1 ra vared konad bad entar bezanad dar voroodi gereftan badi(harkat jadid) in enter voroodi jadid */
			/*hesab mishavad pas haminja an ra daryaft mikonim va agar in voroodi enter nabashad yani voroodi chizi gheyr az dokme 1 khali boode*/
			/*pas barname payan miyabad*/
			if (gaming == 1)
			{
				scanf_s("%c", &newMove);
				if (newMove != '\n')
				{
					gaming = 2;
				}
			}
			continue;
		}

		/*Harkat jadid*/
		moves += 1;
		if (turn == 1)
		{
			printf("Player one's turn:\n");
		}
		else
		{
			printf("Player two's turn:\n");
		}
		printf("Please choose a number between 1 to 9 : ");
		correctMove = 0;
		while (!correctMove)/*check kardan dorosti voroodi*/
		{
			/*dar inja check mikonim ke voroodi yek character bashad*/
			numberOfChars = 0;
			newMove = 's';
			while (newMove != '\n')
			{
				numberOfChars++;
				scanf_s("%c", &newMove);
				if (numberOfChars == 1)
				{
					firstIn = newMove;
				}
				/*chon momken ast karbar ghabl az ragham khod 0 ya space bezand in do mored ra agar dar ebtedaye voroodi boodand hazf mikonim*/
				if ((numberOfChars==1) && ((newMove == '0') || (newMove==' ')))
				{
					numberOfChars--;
				}
			}
			if (numberOfChars != 2)/*dar in halat tedad voroodi bish az yeki ast*/
			{
				printf("Your move is not correct! Please try again and insert a number between 1 to 9 :\n");
				continue;
			}
			newMove = firstIn;
			/**/
			if (newMove == '1')
			{
				if (c1 == ' ')
				{
					if (turn == 1)
					{
						c1 = 'X';
					}
					else
					{
						c1 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '2')
			{
				if (c2 == ' ')
				{ 
					if (turn == 1)
					{
						c2 = 'X';
					}
					else
					{
						c2 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '3')
			{
				if (c3 == ' ')
				{
					if (turn == 1)
					{
						c3 = 'X';
					}
					else
					{
						c3 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '4')
			{
				if (c4 == ' ')
				{
					if (turn == 1)
					{
						c4 = 'X';
					}
					else
					{
						c4 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '5')
			{
				if (c5 == ' ')
				{
					if (turn == 1)
					{
						c5 = 'X';
					}
					else
					{
						c5 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '6')
			{
				if (c6 == ' ')
				{
					if (turn == 1)
					{
						c6 = 'X';
					}
					else
					{
						c6 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '7')
			{
				if (c7 == ' ')
				{
					if (turn == 1)
					{
						c7 = 'X';
					}
					else
					{
						c7 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '8')
			{
				if (c8 == ' ')
				{
					if (turn == 1)
					{
						c8 = 'X';
					}
					else
					{
						c8 = 'O';
					}
					correctMove = 1;
				}
			}
			if (newMove == '9')
			{
				if (c9 == ' ')
				{
					if (turn == 1)
					{
						c9 = 'X';
					}
					else
					{
						c9 = 'O';
					}
					correctMove = 1;
				}
			}
			if (!correctMove)
			{
				printf("Your move is not correct! Please try again and insert a number between 1 to 9 :\n");
			}
		}
		/*Chap Jadaval*/
		printf("\n");
		printf("     |     |   \n");
		printf("  %c  |  %c  |  %c\n", c1, c2, c3);
		printf("_____|_____|_____\n");
		printf("     |     |   \n");
		printf("  %c  |  %c  |  %c\n", c4, c5, c6);
		printf("_____|_____|_____\n");
		printf("     |     |   \n");
		printf("  %c  |  %c  |  %c\n", c7, c8, c9);
		printf("     |     |     \n");
		printf("\n");

		turn = 3 - turn;/*taviz nobat*/
	}
	return 0;
}