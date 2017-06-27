/* Program to find the frequncy of an element in a sorted array */

#include <stdio.h>
#include <stdlib.h>

#define size 6

int main(void)
{
	int arr[size];
	int value, prev_count =1 , curr_count =1, highest_count =1, i,j,k;

	printf("Enter the element of the array.\n");

	for (i = 0; i< size ; i++)
	{
		scanf("%d", &arr[i]);
	}

	for(i = 0 ; i < size ; i++)
	{
		printf("i is %d\n", i );
		for(j = i +1 ; j < size;j++)
		{
		        printf("j is %d\n", j );
			if (arr[i] == arr[j])
			{
				curr_count = curr_count + 1;
		                printf("curr_count is %d\n", curr_count );
				if ( j == size-1 && highest_count < curr_count)
				{
					highest_count  = curr_count;
					value = arr[j];
					i = j;
					break;
				}

			}

			

			else 
			{
				i = j-1;
				if(highest_count < curr_count)
				{
					highest_count  = curr_count;
					value = arr[i];
				}
				curr_count = 1;
				break;
			}
		}
	}

	printf("\nValue : %d, Frequency : %d\n", value, highest_count);

	return 0;
}







