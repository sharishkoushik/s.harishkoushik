/* BST implementation using arrays */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int arr[SIZE];

int main(void)
{
	int par, root=1, rchild=0, lchild=0, item, i;
	char c;
	par = root;
	for( i =0 ; i< 7 ; i++)
	{
		arr[i] = 0;
	}

	printf("Initial values in the array ...\n");
	for( i = 1; i < 7 ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	for( i =1 ; i < SIZE; i++)
	{
		printf("Enter an item : ");
		scanf("%d", &item);
		par = root;

		while(arr[par] != 0 )
		{
			printf("par is : %d\n", par);
			if(item < arr[par])
			{
				lchild = 2*par;
				printf("lchild is : %d\n", lchild);
				par = lchild;
			}
			else if(item > arr[par])
			{
				rchild = 2*par+1;
				printf("rchild is : %d\n", rchild);
				par = rchild;
			}
			else
			{
				printf("Duplicate key\n");
				break;
			}
			printf("par is : %d\n", par);
		}
		arr[par] =item;
		printf("Item inserted in arr[%d] is :%d\n", par,item);

	}
	 for( i = 1; i < SIZE; i++)
	{
		if(arr[i] == 0)
			continue;
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

