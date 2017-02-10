/*Program to Implent a stack in an array, with zeroth element as the top of the stack*/ 

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int arr[MAX];
int i = -1, top = -1;

void push(int);
int pop();
void display();

int main()
{
	int item, choice;
        while(1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : 
			printf("Enter the item in the stack : ");
			scanf("%d", &item);
			push(item);
			break;

			case 2 :
			item = pop();
			printf("Popped item is : %d\n", item);
			break;

			case 3 :
			printf("The elements in the stack are : \n");
			display();
			break;

			default:
			printf(" Wrong Choice! \n");
			break;
		}
	}
}

void push(int item)
{
	int j;
	if ( i == MAX-1)
		printf("Stack is Full\n");
	
	else if (i == -1)
	{
		top = top + 1;
		i = i + 1;
		arr[i] = item;
	}

	else
	{
		i = i + 1;
		for (j = i - 1; j >= 0; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[0] = item;
	}
}

int pop()
{
	int j,tmp;
	if(i == -1)
	{
		printf("Stack is Empty\n");
		return 0;
	}
	
	else if( i == 0)
	{
		tmp = arr[i];
		i = i - 1;
		return tmp;
	}

	else
	{
		tmp  = arr[0];
		for(j = 0; j <= i; j++)
		{
			arr[j] = arr[j + 1];
		}
		i = i - 1;
		return tmp;
	}
}

void display()
{
	int j;
	for(j = 0; j <= i ; j++)
		printf("%d\n", arr[j]);
	
}


