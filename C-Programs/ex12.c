#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	int ch,c1,c2;
	if((fptr = fopen("myfile", "r")) == NULL)
	{
		printf("File Opening Error\n");
	}
	c1 = fgetc(fptr);
	fputc(c1,stdout);
	c2 = fgetc(fptr);
	fputc(c2,stdout);
	printf("\n");
	/*while((ch = fgetc(fptr)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(fptr);*/
	return 0;
}


