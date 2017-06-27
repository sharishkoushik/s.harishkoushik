/* Program to to delete common characters from two string and print them.
 * Length of string1 is fgreater than length of string2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char s1[100], s2[100], (*ptr1)[100], (*ptr2)[100];
	strcpy(s1, "harish koushik");
	strcpy(s2, "Hh kus");
	ptr1 = &s1;  
	ptr2 = &s2;

	int i,j,k,l,m,n;

	m = strlen(s1);
	n = strlen(s2);

	for( i =0 ; i < m ; i++)
	{
		for(j = i +1 ; j < m ; j++)
		{
			if(s1[i] == s1[j])
			{
				for(k = j ; k < m ; k ++)
				{
					s1[k] = s1[k+1];
				}
				m--;
			}
		}
	}

	printf("new s1 is : %s\n", *ptr1);

	for(i = 0 ; i < m ; i ++)
	{
		for(j = 0 ; j < n; j++)
		{
			if(s1[i] == s2[j])
			{
				for(k = j ; k< m ; k++)
				{
					s2[k] = s2[k + 1];
				}
				n --;
				
				for (l = i ; l < m ; l++)
				{
					s1[l] = s1[l+1];
				}
				m --;
			}
		}
	}
	printf("new s1 is : %s\n", *ptr1);
	printf("new s1 is : %s\n", *ptr2);

	return 0;
}
