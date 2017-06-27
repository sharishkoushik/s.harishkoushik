#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80

int main(void)
{
	FILE *fp;
	char str[MAX];
	int i, j, count=0;
	if((fp = fopen("text", "r")) == NULL)
	{
		perror("No file present");
	}

	/*while(fgets(str, 80, fp) != NULL)
	{
		//printf("%s", str);
		fputs(str, stdout);
	}

	return 0;*/

	while(fgets(str, 80, fp) != NULL)
	{
		for(i = 0; str[i] != '\0' && i < MAX; i++)
		{
			if(str[i] == ' ' || str[i] == '.')
			{
				continue;
			}
			else
			{
				for(j = i; str[j] != ' ' ; )
				{
					j++;
				}
				count++;
				if(j == MAX)
				{
					break;
				}
				else
				{
				        i = j;
				}
			}
		}
	}
	printf("count is : %d\n", count);
	return 0;
}
