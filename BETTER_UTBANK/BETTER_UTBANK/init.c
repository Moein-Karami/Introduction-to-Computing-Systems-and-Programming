#include "CONST_VAL_FUNC_LIB_STRUCT.h"
void init_user(user* person)/*set default information for users*/
{
	strcpy(person->name, "admin");
	strcpy(person->pass, "123");
	strcpy(person->tel, "00000000000");
	person->id = 0;
	person->money = 0;
	person->next = NULL;
	person->num_of_operation = 0;
	person->oper = malloc(sizeof(operation));
	person->oper->next = NULL;
}
void list_to_file(char* file_name, user* admin_user)/*write information from link list to file*/
{
	remove(file_name);
	FILE* admin_file = fopen(file_name, "w");
	if (admin_file == NULL)
	{
		printf("FAIL TO SAVE DATA\n");
		return;
	}
	operation* temp;
	fprintf(admin_file, "%d %d\n", admin_user->money, admin_user->id);/*write number of customers and the maximum id*/
	admin_user = admin_user->next;/*first customer*/
	while (admin_user != NULL)
	{
		fprintf(admin_file, "%s\n", admin_user->name);
		fprintf(admin_file, "%s\n", admin_user->pass);
		fprintf(admin_file, "%s\n", admin_user->tel);
		fprintf(admin_file, "%d\n", admin_user->id);
		fprintf(admin_file, "%d\n", admin_user->money);
		fprintf(admin_file, "%d\n", admin_user->num_of_operation);
		temp = admin_user->oper->next;
		while (temp != NULL)/*write opertions of customer to file*/
		{
			fprintf(admin_file,"%s %d\n", temp->command, temp->val);
			temp = temp->next;/*next operation*/
		}
		admin_user = admin_user->next;/*next customer*/
	}
	fclose(admin_file);
}
void file_to_list(char* file_name, user* admin_user)/*write information from file to link list*/
{
	int num_of_users, max_id;
	int i, j;
	user* tmp,*curr_user;
	operation* oper_tmp,*curr_oper;
	FILE* admin_file = fopen(file_name, "r");
	if (admin_file == NULL)
	{
		printf("FAIL TO READ OLD INFORMATIONS\nMAKING NEW ONE ...\n");
		admin_file = fopen(file_name, "w");
		if (admin_file == NULL)
		{
			printf("FAIL AGAIN\n");
			exit(0);
		}
		fprintf(admin_file, "0 0\n");
		fclose(admin_file);
		admin_file = fopen(file_name, "r");
	}
	check(fscanf(admin_file, "%d %d", &num_of_users, &max_id),2);
	admin_user->money = num_of_users;
	admin_user->id = max_id;
	curr_user = admin_user;
	for (i = 1;i <= num_of_users;i++)
	{
		
		tmp = malloc(sizeof(user));
		if (tmp == NULL)
		{
			printf("Fail to build list\n");
			exit(1);
		}
		init_user(tmp);
		tmp->next = curr_user->next;/*add user to end of list*/
		curr_user->next = tmp;
		check(fscanf(admin_file, "%s", tmp->name),1);
		check(fscanf(admin_file, "%s", tmp->pass),1);
		check(fscanf(admin_file, "%s", tmp->tel),1);
		check(fscanf(admin_file, "%d", &(tmp->id)),1);
		check(fscanf(admin_file, "%d", &(tmp->money)),1);
		check(fscanf(admin_file, "%d", &(tmp->num_of_operation)),1);
		curr_oper = tmp->oper;
		for (j = 1;j <= tmp->num_of_operation;j++)
		{
			oper_tmp = malloc(sizeof(operation));
			if (oper_tmp == NULL)
			{
				printf("Fail to build list\n");
				exit(1);
			}
			oper_tmp->next = curr_oper->next;/*add this operation to end of list of operations of this custopmer*/
			curr_oper->next = oper_tmp;
			check(fscanf(admin_file, "%s", oper_tmp->command),1);
			check(fscanf(admin_file, "%d", &(oper_tmp->val)),1);
			curr_oper = oper_tmp;/*new operation is last operation now*/
		}
		curr_user = tmp;/*new customer is new customer now*/
	}
	fclose(admin_file);
}