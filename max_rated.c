#include<stdio.h>
#include"struct.h"
#include<stdlib.h>
void max_rating()
{
	FILE *fp = fopen("goods.txt","rb");
	struct goods product;
	float max_rating = 0.0;
	printf("\n");
	while(fread(&product,sizeof(struct goods),1,fp))
	{
		if(max_rating<product.rating)
			max_rating = product.rating;
	}
	fclose(fp);
	fp = fopen("goods.txt","rb");
	while(fread(&product,sizeof(struct goods),1,fp))
	{
		if(max_rating == product.rating)
			printf("%s %s %s %.2f %.2f %.2f\n",product.name,product.type,product.brand,product.cost, product.rating, product.quantity);
	}
	printf("\n");
	fclose(fp);
}
