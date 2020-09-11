#include <stdio.h>
#include "struct.h"

int add()
{
	struct goods add;
	FILE *data;
	data = fopen("goods.txt","a");
	long int i=1;
	for(long int j=1;j<=i;j++)
	{
		printf("Enter name : ");	
		scanf("%s",add.name);
		printf("Enter type : ");
		scanf("%s",add.type);
		printf("Enter brand : ");
	      	scanf("%s",add.brand);
		printf("Enter cost : ");
       		scanf("%f",&add.cost);
		printf("Enter rating : ");
        	scanf("%f",&add.rating);
		printf("Enter quantity : ");
	        scanf("%f",&add.quantity);
	}

	fwrite(&add,sizeof(struct goods),1,data);
	fclose(data);
	return 0;
}
