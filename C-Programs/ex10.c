/* Program to add the elements of an arrayy */

#include <stdio.h>

int main()
{
	int i, sum=0, arr[10];
	for(i =0; i < 10; i++)
	{
		printf("Enter the value if arr[%d] : ", i);
		scanf("%d", &arr[i]);
		sum = sum + arr[i];
	}
	printf("The sum is %d\n", sum);
	return 0;
}

