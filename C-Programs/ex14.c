#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	int i;
	char str[80];
	fp = fopen("myfile" , "r");
	if(fp == NULL)
	{
		printf("Error opening the file\n");
		exit(1);
	}
	fgets(str, 100, fp); 
	/*while(fgets(str, 100, fp) != NULL)
	{
		fputs(str, stdout);
		//printf("%s", str);
	}*/
        for (i = 0 ; i< 80 ; i++)
	{
		printf("%c", str[i]);
	}

	fclose(fp);
	return 0;
}


