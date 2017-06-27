#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	char str[] = " S Harish Koushik";
	char *p;
	p = malloc(sizeof(str));
	strcpy(p, str);
	int i,j,k=0;
	i =0;
		if(str[0] != ' ')
		{
			putc(str[0], stdout);
			k++;
		}
	for(i=k, j=i+1; str[j] != '\0'; i++,j++)
	{
		if(str[i] == ' ' && str[j] != ' ')
		{
			putc(str[j], stdout);
		}
	}
	printf("\n");
	return 0;
}

