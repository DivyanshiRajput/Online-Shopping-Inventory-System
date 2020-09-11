#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void costliest()
{
	struct goods g1;
	double expensive, cheap;
	double temp1, temp2;
	int i;
	FILE *fptr;
	fptr= fopen("goods.txt", "r");
	temp1= g1.cost;
	while (fread(&g1, sizeof( struct goods), 1, fptr))
	{
		if (g1.cost > temp1)
			temp1= g1.cost;
		expensive= temp1;
	}
	fclose(fptr);

	fptr= fopen("goods.txt", "r");
	printf("\nCostliest good : \n");
	while(fread(&g1,sizeof(struct goods),1,fptr))
	{
		if(g1.cost == expensive)
		{
			printf("%s %s %s %.2f %.2f %.2f\n",g1.name,g1.type,g1.brand,g1.cost,g1.rating,g1.quantity);
		}
	}
	fclose(fptr);
}
