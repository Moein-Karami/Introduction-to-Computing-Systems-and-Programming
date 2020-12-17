#include "CONST_VAL_FUNC_LIB_STRUCT.h"

void check(int inp, int exp)/*check returned value of fscanf*/
{
	if (inp != exp)
	{
		printf("Wrong information in file\n");
		exit(1);
	}
}

int check_stream()/*check if buffer is empty or not*/
{
	char inp;
	int wrong = 0;
	while ((inp=getchar()) != '\n')
		if (inp != ' ')
			wrong = 1;
	if (wrong)
		printf("Access denied\n");
	return wrong;
}