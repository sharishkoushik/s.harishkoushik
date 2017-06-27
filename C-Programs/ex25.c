/* Program to remove leading and trailinf zeros in a string  and case
 * sensitive ordering of characters in a string */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*int main(void)
{
	char str[] = "   What are you doing", seps[] = " ";
	char *t;
	t = strtok(str, seps);
	while(t != NULL)
	{
		printf("%s", t);
		t=strtok(NULL, seps);
	}
	printf("\n");
	return 0;
}*/

int main(void)
{
	char str1[] = "Harish", tmp, c;
	int i,j;
	for(i = 0; i < strlen(str1) ; i++)
	{
		for(j = i ; j < strlen(str1) ; j++)
		{
			if( isupper(str1[j]) )
			{
				c=tolower(str1[j]);
				printf("c is  : %c\n", c);
				str1[i] = c;
			}
			if(str1[i] > str1[j])
			{
				tmp = str1[j];
				str1[j] = str1[i];
				str1[i] = tmp;
			}
			else
			{
				continue;
			}
		}
	}
	puts(str1);
	return 0;
}


