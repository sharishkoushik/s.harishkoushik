#include <stdio.h>
void displayBits(int x);
int main()
{
	int a,b;
	printf("Enter the vlaues of a, b in hexadecimal: ");
	scanf("%x%x", &a, &b);
	printf("a|b=%X\n",a|b); //displayBits(a);
	return 0;
}

