/* Program to print a hour glass in a 6x6 array*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COL 4

int main(void)
{
	int arr[ROWS][COL], i,j,k,l,mid=0,k_limit, l_limit, highest=0;
	printf("Enter the elements in the Matrix\n");
	for(i =0 ; i< ROWS; i++)
	{
		for(j =0 ; j < COL ; j++)
		{
			printf("Element %d,%d : ", i,j);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("The elements int the matrix are : \n");
	for(i =0 ; i< ROWS; i++)
	{
		for(j =0 ; j < COL ; j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}

	printf("Hour glass matrix is : \n");

	for (i =0 ;  i < ROWS-2 ; i++)
	{
		k_limit = i + 3;
		for(j =0 ; j < COL-2 ; j++)
		{
			l_limit = j +3;
			int sum =0;
			for(k =i ; k <k_limit ; k++)
			{
				if(k == i + 1)
				{
					if(mid < COL-1)
					{
						mid = mid+1;
					}
					if(mid == COL-1)
					{
						mid =1;
					}
					printf("%10d\n", arr[k][mid]);
					sum = sum + arr[k][mid];
					continue;
				}
				for(l =j; l< l_limit; l++)
				{
					printf("%5d", arr[k][l]);
					sum = sum + arr[k][l];
				}
				printf("\n");
			}
			printf("The sum of the hour glass is : %d", sum);
			if (highest <= sum)
			{
				highest = sum;
			}
			printf("\n");
			printf("\n");
		}
	}
	printf("\n");
	printf("The highest sum of the hour glass is : %d\n ", highest);
	return 0;

}
