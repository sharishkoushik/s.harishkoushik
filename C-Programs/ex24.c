/* Program to coverto uppercase(below) and case insensitivity */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main(void)
{
	char *p1, *p2;
	p1 = "HARISH";
	p2 = "Larish";

	while(*p1 != '\0')
	{
		
		if(*p2 == *p1 + 32)
		{
			p1++; p2++;
			continue;
		}

		else
			return -1;
	}
	printf("case insensitive\n");
	return 0;
}*/

int  main(void)
{
	char *p1, str[100], str1[100];
	fgets(str1, 100, stdin);
	puts(str1);

	p1 = "harish";
	int i,j;
	j = strlen(p1);
	printf("string length of p1 : %d\n", j); 
	for( i =0; i < j; i++)
	{
		str[i] = *p1 - 32;
		p1++;
	}
	puts(str);
	return 0;
}
