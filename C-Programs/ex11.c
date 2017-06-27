#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char ch;
	if((fptr=fopen("myfile" , "w+")) == NULL)
	{
		printf("Error in opening the file\n");
		exit(1);
	}
	printf("Enter text : \n");
	ch = getchar();
	while(ch != EOF)
	{
		fputc(ch, fptr);
		ch = getchar();
	}
	fclose(fptr);
	return 0;
}



