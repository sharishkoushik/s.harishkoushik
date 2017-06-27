#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *p, (*ptr)[100], str[100];
	strcpy(str, "HARISH KOUSHIK");
	ptr = &str;
	p = "harish koushik";
	//puts(*ptr); 
	//puts(p); 
	//printf("%s\n", p); 
	printf("%s\n", *ptr); 
	if(strcasecmp(str, p) == 0)
	{
		printf("case insensitive\n");
	}
	return 0;
}
