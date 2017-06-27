#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ch;
	printf("Enter a character : ");
	while((ch = getchar()) != EOF)
	{
	putchar(ch);
	}
	return 0;
}

