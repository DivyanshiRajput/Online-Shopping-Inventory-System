#include<stdio.h>
#include"struct.h"
#include<stdlib.h>
#include<string.h>

void good_type(char *type)
{
	FILE *fp = fopen("goods.txt" , "r");
	struct goods product;
	int a = 1;

	while(fread(&product, sizeof(struct goods), 1, fp))
	{
		if(strcmp(product.type,type) == 0)
		{
			a = 0;
			printf("%s %s %s %2f %2f %2f \n",product.name,product.type,product.brand,product.cost,product.rating,product.quantity);
		}
	}
	if(a == 1)
	{
		printf("Type not found\n");
	}
	fclose(fp);
}
