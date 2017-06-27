/* Program to count the number of vowels in a string */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count_vowel(char s[], int ,int);
int main(Void)
{
	char str[100];
	strcpy(str, "hari");
	int count;
	count_vowel(str, 0 , 0);
	//printf("No. of vowels in the string is %d\n", count);
	return 0;
}

void count_vowel(char s[], int count , int i)
{
	if(s[i] != '\0')
	{
		//printf("s[i] is %c\n", s[i]);
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			i++;
			//printf("If : count is %d\n", count);
			count_vowel(s, count, i);
			count++;
			printf("If : after count is %d\n", count);
			//return count;
		}
		else
		{
			i++;
			//printf("Else : before count is %d\n", count);
			count_vowel(s,count,i);
			//printf("Else : after count is %d\n", count);
			//return count;
		}
	}
	//if(s[i] == '\0')
        	//printf("No. of vowels in the string is %d\n", count);

}
