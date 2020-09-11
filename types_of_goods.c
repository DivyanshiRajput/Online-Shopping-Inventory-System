#include"struct.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int types_of_goods()
{
	FILE *fp = fopen("goods.txt","r");
	FILE *tp = fopen("types.txt","w");
	struct goods product;
	
	int i=0,j=0;
	char k[100][20],uk[100][20];
	while(fread(&product,sizeof(struct goods), 1, fp))
	{
		strcpy(k[i], product.type);
		fprintf(tp,"%s\n",k[i]);
		i += 1;
	}
	fclose(fp);
	fclose(tp);

	FILE *utp = fopen("unique_types.txt","w");
	fread(&k,sizeof(k),1,tp);
	for(j=0;j<i;j++)
		strcpy(uk[j],k[j]);
	
	
	j=0;
	int kk=0;
	while(j<i)
	{
		kk = j+1;
		while(kk<i)
		{
			if(strcmp(uk[j],uk[kk]) == 0)
			{
				uk[kk][0] = '\0';
			}
			kk += 1;
		}
		j += 1;
	}
	int qwe = 0;
	for(j=0;j<i;j++)
	{
		if(uk[j][0] != '\0')
		{
			fprintf(utp,"%s\n",uk[j]);
			printf("%d : %s\n",qwe+1,uk[j]);
			qwe++;
		}
	}
	fclose(tp);
	fclose(utp);
}
