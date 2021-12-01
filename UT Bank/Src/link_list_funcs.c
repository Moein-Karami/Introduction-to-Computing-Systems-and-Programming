#include "CONST_VAL_FUNC_LIB_STRUCT.h"

user* find(user* admin_user, char* name,char* tel)/*search to list of customers to check the name or telephone number exist or not*/
{
	while (admin_user != NULL)
	{
		if (strcmp(admin_user->name, name) == 0)
			return admin_user;
		if (strcmp(admin_user->tel, tel) == 0)
			return admin_user;
		admin_user = admin_user->next;/*check next user*/
	}
	return NULL;
}
void add_to_users(user* admin_user, user* new_user)/*add a user to end of the users list*/
{
	while (admin_user->next != NULL)
		admin_user = admin_user->next;
	admin_user->next = new_user;
}
void add_to_operations(operation* first, operation* last)/*add an operation to end of operations list*/
{
	while (first->next != NULL)
		first = first->next;
	last->next = NULL;
	first->next = last;
}