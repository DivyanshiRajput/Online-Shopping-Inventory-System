#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"


int delete()
{

	struct goods item;
	FILE *f, *f1;
	char tdel[30], name[30];
	int flag = 0;
	int total = 0, valid = 0;
	f = fopen("goods.txt", "r");
	f1 = fopen("temp.txt", "w");
	
	printf("\n\nEnter the type of item you want to delete: ");
	scanf("%s", tdel);

	printf("Names of items under this type:\n\n");

	while(fread(&item, sizeof(struct goods), 1, f))
	{
		if(strcmp(item.type, tdel) == 0)
		{
			printf("%s\n", item.name);
			flag = 1;
		}
	}

	fseek(f, 0, SEEK_SET);

	if(flag == 0)
	{
		printf("\n\nInvalid type...");
		remove("temp.txt");
		fclose(f);
		fclose(f1);
		return 0;
	}

	else
	{
		printf("\n\nEnter the name of the item you want to delete: ");
		scanf("%s", name);


		while(fread(&item, sizeof(struct goods), 1, f))
	        {       
			total++;
                	if(strcmp(item.name, name) != 0)
        	        {
				valid++;
                        	fwrite(&item, sizeof(struct goods), 1, f1);
                	}
        	}

		if(total == valid)
		{
			printf("\n\nEntry not found");
			fclose(f);
			fclose(f1);
			remove("temp.txt");
			return 0;
		}

		else
		{
			fclose(f);
			remove("goods.txt");
			rename("temp.txt", "goods.txt");
			fclose(f1);
			return 1;
		}
	}
}
