#include "CONST_VAL_FUNC_LIB_STRUCT.h"
/*admin id is the maximum id which exist*/
/*admin money is number of customers*/
int admin_commands(user* admin_user)
{
	char command[COM_SIZE];
	scanf("%s", command);
	if (strcmp(command, "logout") == 0)
		return 0;
	else if (strcmp(command, "exit") == 0)
		return -1;
	else if (strcmp(command, "add_user") == 0)
		add_user(admin_user);
	else if (strcmp(command, "deposit") == 0)
		deposit(admin_user);
	else if (strcmp(command, "view") == 0)
		admin_view(admin_user);
	else if (strcmp(command, "withdraw") == 0)
		withdraw(admin_user);
	else if (strcmp(command, "delete") == 0)
		delete(admin_user);
	else
	{
		printf("ACCESS DENIED\n");
		while (getchar() != '\n');/*clean stream*/
	}
	return 1;
}
int user_commands(user* admin_user,char* name)
{
	char command[COM_SIZE];
	scanf("%s", command);
	if (strcmp(command, "logout") == 0)
		return 0;
	else if (strcmp(command, "exit") == 0)
		return -1;
	if (strcmp(command, "transfer") == 0)
		transfer(admin_user, name);
	else if (strcmp(command, "view") == 0)
		user_view(admin_user, name);
	else
	{
		printf("ACCESS DENIED\n");
		while (getchar() != '\n');/*clean stream*/
	}
	return 1;
}
int main()
{
	user *admin_user = malloc(sizeof(user));
	if (admin_user == NULL)
	{
		printf("FAIL TO create admin account\n");
		return 0;
	}
	char name[NAME_SIZE];
	int procces = 0;
	init_user(admin_user);
	file_to_list("admin.txt", admin_user);/*read information from file*/
	printf("HELLO\nWelcome to our bank\nWhat can I do for you my friend?\n");
	do {
		while (procces == 0)/*no one logged in*/
		{
			procces = login(admin_user, name);
			if(procces==1)
				printf("Welcome %s\n", name);
		}
		if (procces == 1)/*some one logged in*/
			printf("\nWhat can I do for you %s ?\n", name);
		if (procces == -1)
			break;
		if (strcmp(name, "admin") == 0)/*admin logged in*/
			procces = admin_commands(admin_user);
		else/*a user logged in*/
			procces = user_commands(admin_user, name);
		if (procces == 0)
			printf("\nWhat can I do for you my friend?\n");
		
	} while (procces!=-1);
	list_to_file("admin.txt", admin_user);/*write information to file*/
}