#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	/*struct record
	{
		char name[20];

	}stu;
	FILE *fp;
	int choice = 1;
	fp = fopen("stu", "ab");
	if(fp == NULL)
	{
		printf("Error in opening a file \n");
		exit(1);
	}
	while(choice ==1 ){
		printf("Enter name : ");
		scanf("%s", stu.name);
		fwrite(&stu, sizeof(stu), 1, fp);
		scanf("%d", &choice);
	}
	
	return 0;*/
	FILE *fptr;
	int ch;
	fptr = fopen("myfile", "r");
	if(ferror(fptr))
	{
		printf("Error\n");
	}
	else
		ch = fgetc(fptr);
		fputc(ch, stdout);
	fclose(fptr);
	return 0;
}

