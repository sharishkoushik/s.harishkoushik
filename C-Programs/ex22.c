#include <stdio.h>
#include <string.h>
void del_char(char *, char ch);

/*int main(void)
{
	char str[] = "...why?but;not?oh!, where when";
	char seps[] = "?!;,. \t";
	char *t;
	t = strtok(str, seps);
	printf("%s ", t);
	while(t != NULL)
	{
		printf("%s ", t);
		t = strtok(NULL, seps);
	}
	printf("\n");
	return 0;
}*/

int main(void)
{
	char str1[] = "What are you doing";
	char str2[100], *tmp;
	strcpy(str2, str1);
	printf("str2 using printf : %s\n", str2);
	printf("str2 using puts : ");
	puts(str2);
	tmp = str2;
	printf("tmp usinf printf : %s\n", tmp);
	printf("tmp using puts :");
	puts(tmp);

	tmp = "S Harish Koushik";
	int i;
	for(i = 0 ; i < strlen(tmp) ; i++)
	{
		printf("tmp[%d] is %c\n", i, tmp[i]);
	}

	printf("print using *tmp : \n");
	//printf("%c\n", *tmp);

	while(*tmp != '\0')
	{
		printf("%c\n", *tmp++);
		//tmp = tmp +1;
	}
	return 0;
}

/*int main(void)
{
	char str[50] = "Data Structures through C in depth";
	del_char(str, 'u');
	puts(str);
	return 0;
}
void del_char(char *str, char ch)
{
	int i,j;
	for(i=0,j=0; i < strlen(str) -1; i++)
	{
		if(str[i] != ch)
		{
			str[j] = str[i];
			j = j+1;
		}
	}
	str[j] ='\0';
}*/
