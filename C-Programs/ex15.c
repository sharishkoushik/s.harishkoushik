/* Program to demonstrate the use of fwrite */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record
{
	char name[20];
	int marks;
};

typedef struct record record;
record stu[3];

int main(void)
{
	FILE *fp;
	fp = fopen("student_record", "wb");
	if(fp == NULL)
	{
		perror("Records not present");
		exit(1);
	}
	for(int i =0; i < 3 ; i++)
	{
		printf("Enter the name of the student %d: ", i);
		scanf("%s", stu[i].name);
		printf("Enter the marks of the student %d: ", i);
		scanf("%d", &stu[i].marks);
	}
	fwrite(&stu, sizeof(stu), 1, fp);
	fclose(fp);
	
	fp = fopen("student_record", "rb");
	if(fp == NULL)
	{
		perror("Records not present");
		exit(1);
	}
	printf("\nNAME\tMARKS\n");
	int sum=0;
	//while(fread(&stu, sizeof(stu), 1, fp))
	for(int i = 0; i< 3 ; i++)
	{
		fread(&stu, sizeof(stu[i]), 1, fp);
		printf("%s\t", stu[i].name);
		printf("%d\n", stu[i].marks);
		sum = sum + stu[i].marks;
		
	}
	printf("TOTAL\t%d\n", sum);
	fclose(fp);
	return 0;
	
}
	
