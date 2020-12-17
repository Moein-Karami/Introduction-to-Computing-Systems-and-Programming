#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NAME_SIZE 15
#define COM_SIZE 60


struct User{
	char name[NAME_SIZE];
	char pass[NAME_SIZE];
	char tel[NAME_SIZE];
	int id;
	int money;
	struct User* next;
	int num_of_operation;
	struct Operation* oper;
} ;
struct Operation{
	char command[COM_SIZE];
	int val;
	struct Operation* next;
};

typedef struct User user;
typedef struct Operation operation;

/*Commands*/
int login(user* admin_user, char* name);
void add_user(user* amdin_user);
void deposit(user* admin_user);
void admin_view(user* admin_user);
void withdraw(user* admin_user);
void delete(user* admin_user);
void transfer(user* admin_user, char* name);
void user_view(user* admin_user, char*name);


/*init*/
void list_to_file(char* file_name, user* admin_user);
void file_to_list(char* file_name, user* admin_user);
void init_user(user* person);
void say_hello();

/*link list funcs*/
user* find(user* admin_user, char* name, char* tel);
void add_to_users(user* admin_user, user* new_user);
void add_to_operations(operation* first, operation* last);

/*check */
void check(int inp, int exp);
int check_stream();
