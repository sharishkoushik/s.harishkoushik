/* Program to count the number of words in a file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	int i,count=0;
	char line[80];
	fp = fopen("text", "r");
	if(fp == NULL)
	{
		printf("No file|N");
	}
        while(fgets(line, 80, fp) != NULL)
	{
		for( i= 0 ; line[i] != '\0' ; i++)
		{
			printf("%c\n", line[i]);
			is_end(line[i]);
			count++;
		}
	}
		printf("No of words in the file is : %d\n", count);
		fclose(fp);
		return 0;
}

int is_end(int ch)
{
	switch(ch)
	{
		case '\n': case '\t': case ' ': case ',': case '.':  case ':': case ';' :case'-': 
		return 1;
	}
	return 0;
}

