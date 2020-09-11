#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "by_brand.h"
//#include "price_range.h"
#include "goods_in_price_range.h"
#include "costliest.h"
#include "cheapest.h"
#include "max_rated.h"
#include "display_all_goods.h"
#include "good_of_same_type.h"
#include "add_goods.h"
#include "types_of_goods.h"
#include "delete.h"

void add_user()
{

	char name[30];
	FILE *f;	

	printf("\n\nEnter the user that has to be added: ");
	scanf("%s", name);

	f = fopen("username.txt", "a");

	fwrite(name, sizeof(char), 30, f);
	fclose(f);
}

void delete_user()
{
	int total = 0, valid_users = 0;
	char name[30], user[30];
	FILE *f, *f1;

	printf("\n\nEnter the user that has to be deleted: ");
	scanf("%s", name);

	if(strcmp(name, "admin") == 0)
		printf("\n\nCannot delete admin...");
	else
	{

		f = fopen("username.txt", "r");
		f1 = fopen("temp.txt", "w");

		while(fread(user, sizeof(char), 30, f))
		{
			total++;

			if(strcmp(user, name) != 0)
			{
				valid_users++;

				fwrite(user, sizeof(char), 30, f1);
			}

		}

		if(total == valid_users)
		{	printf("\nUser not found...\n\n");
			remove("temp.txt");
		}
		else
		{
			fclose(f);
			remove("username.txt");
			rename("temp.txt", "username.txt");
			fclose(f1);
		}

	}
}

void see_user()
{
	int i = 0;
	FILE *f;
	char name[30];
	f = fopen("username.txt", "r");
	printf("\n\nThe users are:\n\n"); 
	while(fread(name, sizeof(char), 30, f))
	{
		i ++;
		if(strcmp(name, "admin") != 0)
			printf("%s\n", name);
		
	}

	if(i == 1)
		printf("\nList empty");

	fclose(f);
}



int admin()
{
	int x;
	do
	{
		system("sleep 1");
		printf("\n\n1.Add users\n2.Delete users\n3.See all users\n4.Switch user\n5.Exit\n\n");
		scanf("%d", &x);
		switch(x)
		{
			case 1:add_user();
			       break;
			case 2:delete_user();
			       break;
			case 3:see_user();
			       break;
			case 4:return x;
		}

	}while(x != 5);

	return 5;

}

int user()
{
	int x;

	do
	{
		system("sleep 1");

		printf("\n\n\n\nWelcome to Catalogue Monitoring System\n\n");
		printf("1.Display all items\n");
		printf("2.Costliest item\n");
		printf("3.Cheapest item\n");
		printf("4.Items of same brand\n");
		printf("5.Search according to price range\n");
		printf("6.Add to catalogue\n");
		printf("7.Remove item from catalogue\n");
		printf("8.Best rated item\n");
		printf("9.Departments\n");
		printf("10.Items of a department\n");
		printf("11.Switch user\n");
		printf("12.Exit\n\n");

		printf("Select an option : ");
		scanf("%d", &x);

		char k9[100];
		char k4[100];

		switch(x)
		{

			case 1:
				display();
				break;
			case 2:
				costliest();
				break;
			case 3:
				cheapest();
				break;
			case 4:
				printf("Select the brand : ");
				scanf("%s",k4);
				by_brand(k4);
				break;
			case 5:
				sort_by_price();
				break;
			case 6:
				add();
				break;
			case 7:
				display();
				delete();	
				break;
			case 8:
				max_rating();
				break;
			case 9:
				types_of_goods();
				break;
			case 10:
				types_of_goods();
				printf("Select the department : ");
				scanf("%s",k9);
				good_type(k9);
				break;
			case 11:return 11;

	

		}

	}while(x != 12);

	return 12;
}
void print()
{
	printf("\n\nEnter username: ");
}

int main()
{
	int flag, end, adm;
	char u_name[30], name[30], x, users[30];
	FILE *f;

	strcpy(name, "admin");
	f = fopen("username.txt", "a");

	fwrite(name, sizeof(char), 30, f);

	fseek(f, 0, SEEK_SET);

	fclose(f);

	f = fopen("username.txt", "r");
	
	do
	{
		sheep:
		flag = 0;
		system("sleep 1");
		print();
		scanf(" %s", u_name);

		while(fread(name, sizeof(char), 30, f))
		{
			
			if(strcmp(name, u_name) == 0)
			{
				flag = 1;
				if(strcmp(name, "admin") == 0)
				{
					adm = admin();
					if(adm == 5)
						return 0;
					else
					{
						fseek(f, 0, SEEK_SET);
						goto sheep;
					}

				}
				else
				{
					end = user();
					if(end == 12)
						return 0;
				}
			}
		}

		if(flag == 0)
		{
			printf("\n\nInvalid username...\n\n");
		}

		fseek(f, 0, SEEK_SET);
	}while(flag == 0 || end == 11);

	fclose(f);

}
