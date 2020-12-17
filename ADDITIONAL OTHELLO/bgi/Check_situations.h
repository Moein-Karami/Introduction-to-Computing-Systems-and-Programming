#include "CONST_VALUES_AND_LIBRARYS.h"
int check_block(char grid[MY_SIZE + 5][MY_SIZE + 5], int turn, int row, int column, int row_change, int col_change);/*barresi mohasereye mohre dar yek khane va yek jahat khas*/
int check_possibility_of_cell(char grid[MY_SIZE + 5][MY_SIZE + 5], int turn, int row, int column);/*barresi mohasereye mohre dar yek khane*/
int check_possibility_of_new_move(int turn, char grid[MY_SIZE + 5][MY_SIZE + 5]);/*barresi tavanayi harkat player dar kol jadval*/