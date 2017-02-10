/*Program to find the factorial of a number without  recurssion*/

#include <stdio.h>

int main()
{
	int i,n;
	unsigned int k=1;
	while(1){
	printf("Factorial : ");
	scanf("%d", &n);
	for(i=n; i>0; i--)
	{
		k = k*i;
	}
	printf("Factorial is : %d\n", k);
	}
	return 0;
}

