#include "CONST_VAL_FUNC_LIB_STRUCT.h"

int login(user* admin_user, char* name)
{
	user* customer;
	char command[COM_SIZE],pass[NAME_SIZE];
	scanf("%s", command);
	if (strcmp(command, "exit") == 0)
		return -1;
	else if (strcmp(command, "login"))
	{
		printf("Please login first\n");
		while (getchar() != '\n');
		return 0;
	}
	scanf("%s%s", name, pass);
	if (check_stream())
		return 0;
	customer = find(admin_user, name, "0");/*search find find user in link list*/
	if (customer == NULL)/*this user doesn't exist*/
	{
		printf("Wrong user name\n");
		return 0;
	}
	if (strcmp(pass, customer->pass))
	{
		printf("Wrong password\n");
		return 0;
	}
	return 1;
}
void add_user(user* admin_user)
{
	user* new_user;
	char new_name[NAME_SIZE], pass[NAME_SIZE], tel[NAME_SIZE];
	scanf("%s%s%s", new_name, pass, tel);
	if (check_stream())
		return ;
	if (find(admin_user, new_name, tel) != NULL)/*serch to check the new name or telephone exist*/
	{
		printf("This information exist already\n");
		return 0;
	}
	new_user = malloc(sizeof(user));
	if (new_user == NULL)
	{
		printf("Fail to add user\n");
		return;
	}
	init_user(new_user);/*set defaut information*/
	strcpy(new_user->name, new_name);
	strcpy(new_user->pass, pass);
	strcpy(new_user->tel, tel);
	new_user->id = admin_user->id;
	admin_user->id++;
	admin_user->money++;
	add_to_users(admin_user, new_user);
}
void deposit(user* admin_user)
{
	char name[NAME_SIZE];
	int money;
	user* curr_user;
	operation* oper;
	scanf("%s%d", name, &money);
	if (check_stream())
		return;
	curr_user = find(admin_user, name, "");/*find username in list*/
	if (curr_user == NULL)/*this user name doesn't exist*/
	{
		printf("Wrong user name\n");
		return;
	}
	oper = malloc(sizeof(operation));
	if (oper == NULL)
	{
		printf("Fail to deposit\n");
		return;
	}
	curr_user->money += money;
	curr_user->num_of_operation++;
	strcpy(oper->command, "deposit");
	oper->val = money;
	add_to_operations(curr_user->oper, oper);/*add this operation to user's operations*/
}
void admin_view(user* admin_user)
{
	user* curr_user;
	operation* oper;
	int number = 1;
	char name[NAME_SIZE];
	scanf("%s", name);
	if (check_stream())
		return;
	curr_user = find(admin_user, name, "");/*search username in list*/
	if (curr_user == NULL)/*this user name doesn't exist*/
	{
		printf("Wrong user name\n");
		return;
	}
	printf("User name : %s\n", name);
	printf("ID : %d\n", curr_user->id);
	printf("Telephone number : %s\n", curr_user->tel);
	printf("Remain money : %d\n", curr_user->money);
	printf("Number of operations : %d\n", curr_user->num_of_operation);
	if(curr_user->num_of_operation)
		printf("Operations : \n");
	oper = curr_user->oper;
	while (oper->next!=NULL)/*print operations*/
	{
		oper = oper->next;
		printf("%d. %s %d\n",number, oper->command, oper->val);
		number++;
	}
}
void withdraw(user* admin_user)
{
	user* curr_user;
	operation* oper;
	char name[NAME_SIZE];
	int money;
	scanf("%s%d", name, &money);
	if (check_stream())
		return;
	curr_user = find(admin_user, name, "");/*search username in list*/
	if (curr_user == NULL)/*this username doesn't exist*/
	{
		printf("Wrong user name\n");
		return;
	}
	if (curr_user->money < money)/*user doesn't have enough money*/
	{
		printf("This user has less money\n");
		return;
	}
	oper = malloc(sizeof(operation));
	if (oper == NULL)
	{
		printf("Fail to withdraw\n");
		return;
	}
	curr_user->money -= money;
	curr_user->num_of_operation++;
	strcpy(oper->command, "withdraw");
	oper->val = -money;
	add_to_operations(curr_user->oper, oper);/*add this operation touser's operations*/
}
void delete(user* admin_user)
{
	char name[NAME_SIZE];
	user* curr_user,*pre_user;
	operation* oper;
	scanf("%s", name);
	if (check_stream())
		return;
	curr_user = find(admin_user, name, "");/*search this username in list*/
	if (curr_user == NULL)
	{
		printf("Wrong user name\n");/*this username doesn't exist*/
		return;
	}
	pre_user = admin_user;
	while (pre_user->next != curr_user)/*find previos user of target user in list*/
		pre_user = pre_user->next;
	while (curr_user->oper->next != NULL)/*delete informations of operations of user*/
	{
		oper = curr_user->oper->next;
		curr_user->oper->next=oper->next;
		free(oper);
	}
	admin_user->money--;/*one of users deleted*/
	free(curr_user->oper);
	pre_user->next = curr_user->next;/*delete user of list*/
	free(curr_user);
}
void transfer(user* admin_user, char *name)
{
	user* curr_user, *target_user;
	operation* curr_oper, *target_oper;
	char target_name[NAME_SIZE];
	int money;
	scanf("%s%d", target_name, &money);
	if (check_stream())
		return;
	curr_user = find(admin_user, name, "");/*searh this username in list*/
	target_user = find(admin_user, target_name, "");/*searh target username in list*/
	if (strcmp(name, target_name) == 0)/*target username is equal to current user's username*/
	{
		printf("You can't do this\n");
		return;
	}
	if (target_user == NULL)/*target username doesn't exist in list*/
	{
		printf("Wrong user name\n");
		return;
	}
	if (curr_user->money < money)/*user doesn't have enough money*/
	{
		printf("You don't have enough money\n");
		return;
	}
	curr_oper = malloc(sizeof(operation));
	target_oper = malloc(sizeof(operation));
	if (curr_oper == NULL || target_oper == NULL)
	{
		printf("Fail to transfer\n");
		return;
	}
	curr_user->money -= money;
	target_user->money += money;
	curr_user->num_of_operation++;
	target_user->num_of_operation++;


	
	strcpy(curr_oper->command, "transfer_to_");
	strcat(curr_oper->command, target_name);
	curr_oper->val = -money;
	add_to_operations(curr_user->oper, curr_oper);/*add this operation to current user's operations list*/

	strcpy(target_oper->command, "transfer_from_");
	strcat(target_oper->command, name);
	target_oper->val = money;
	add_to_operations(target_user->oper, target_oper);/*add this operation to target user's operations list*/
}
void user_view(user* admin_user, char* name)
{
	user *curr_user;
	operation* oper;
	int number = 1;
	curr_user = find(admin_user, name, "");/*find this username in list*/
	printf("User name : %s\n", name);
	printf("ID : %d\n", curr_user->id);
	printf("Telephone number : %s\n", curr_user->tel);
	printf("Remain money : %d\n", curr_user->money);
	printf("Number of operations : %d\n", curr_user->num_of_operation);
	if (curr_user->num_of_operation)
		printf("Operations : \n");
	oper = curr_user->oper;
	while (oper->next != NULL)/*print this user's operations*/
	{
		oper = oper->next;
		printf("%d. %s %d\n",number, oper->command, oper->val);
		number++;
	}
}