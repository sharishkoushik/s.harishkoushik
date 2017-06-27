/* Program not to copy non empty lines to another file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE *fp1, *fp2;
	char *str1;
	str1 = malloc(200);
	fp1 = fopen("myfile" , "r");

	if(fp1 == NULL)
	{
		perror("Unable to opent the file");
	}

	fp2 = fopen("myfile2", "w");
	if(fp2 == NULL)
	{
		perror("Unable to open myfile2 for write");
	}

	while(fgets(str1, 80 , fp1) != NULL)
	{
		if(strcmp(str1, "\n") == 0)
		{
			continue;
		}
		else
		{
			//strup(str1);
			fputs(str1, fp2);
		}
	}

	fcloseall();
	return 0;
}

