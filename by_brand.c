#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"struct.h"
void by_brand(char *brand)
{
	long int a = 1;
	FILE *fptr = fopen("goods.txt" , "rb");
	struct goods items;
	while(fread(&items, sizeof(struct goods), 1, fptr))
	{
		if(strcmp(items.brand,brand) == 0)
		{
			a = 0;
			printf("%s %s %s %.2f %.2f %.2f \n",items.name,items.type,items.brand,items.cost,items.rating,items.quantity);
		}
	}
	if(a == 1)
	{
		printf("Brand not found\n");
	}
	fclose(fptr);
}
