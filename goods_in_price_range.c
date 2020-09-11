#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

void sort_by_price()
{
	float i,j,s,n,count=0,max,min;			//n - number of products.
        int l[100],a=1;
	FILE *fptr = fopen("goods.txt","r");//, *fptr2 = fopen("temp.txt", "w");	
	printf("enter min cost : ");
	scanf("%f",&min);
	printf("enter max cost : ");
	scanf("%f",&max);
	printf("\n");
	if(max>=min)
	{
		struct goods items, op;
		i = 0;
		while(fread(&items,sizeof(struct goods),1,fptr))
		{
			if(min < items.cost && max>items.cost)
			{
				a = 0;
				printf("%s %s %s %.2f %.2f %.2f \n",items.name,items.type,items.brand,items.cost,items.rating,items.quantity);
			}
		}
	}
	if(max<min)
	{
		printf("Wrong Inputs\n\n");
	}
	if(a == 1 && max>=min)
		printf("\nNo Goods in the price range\n");
	fclose(fptr);
}

