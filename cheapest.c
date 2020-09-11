#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void cheapest()
{
	struct goods g1;
	double cheap;
	double temp2;
	int i;
	FILE *fptr;
	fptr= fopen("goods.txt", "r");
	temp2= 10000000;
	while (fread(&g1, sizeof( struct goods), 1, fptr))
	{
		if (g1.cost < temp2)
                        temp2= g1.cost;
		cheap= temp2;
	}
	fclose(fptr);

	fptr= fopen("goods.txt", "r");
	printf("\nCheapest good :\n");
        while(fread(&g1,sizeof(struct goods),1,fptr))
        {
                if(g1.cost == cheap)
                {
                        printf("%s %s %s %.2f %.2f %.2f\n",g1.name,g1.type,g1.brand,g1.cost,g1.rating,g1.quantity);
                }
        }
        fclose(fptr);
}
