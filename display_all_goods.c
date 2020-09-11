#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void display()
{
	printf("\nDisplaying all goods\n");
	struct goods g1;
	int i;
	FILE *fptr;
	fptr = fopen("goods.txt", "rb");
	
	while(fread(&g1, sizeof(struct goods), 1, fptr))
		printf ("%s %s %s %.2f %.2f %.2f\n", g1.name, g1.type, g1.brand, g1.cost, g1.rating, g1.quantity);
	
	fclose (fptr);
	printf("\n");
}	

