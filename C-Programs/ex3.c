/* Program to implement two stacks in a single array */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int arr[MAX];
int top1=-1, top2=MAX;
void push1(int);
void push2(int);
int pop1();
int pop2();
void display(int);

int main()
{
	int stk_choice, item; 
	char choice;
	while(1)
	{
	        printf("A. Push\n");
	        printf("B. Pop\n");
	        printf("C. Display\n");
	        printf("Enter your choice : ");
	        scanf("%c", &choice);
        
	        switch(choice)
	        {
		        case 'A':
			printf("Enter the element to be pushed in the stack : ");
			scanf("%d", &item);
		        printf("Select stack 1 or 2 :");
		        scanf("%d", &stk_choice);
		        
			switch(stk_choice)
		        {
			
			        case 1:
			        push1(item);
			        break;

			        case 2:
			        push2(item);
			        break;

			        default:
			        printf("Enter either 1 or 2\n");
			        break;
		        }
			break;

		        case 'B':
		        printf("Select stack 1 or 2 :");
		        scanf("%d", &stk_choice);
		        switch(stk_choice)
		        {
			        case 1:
			        item = pop1();
				printf("The popped element from Stack-1 is : %d\n", item);
			        break;

			        case 2:
			        item = pop2();
				printf("The popped element from Stack-2 is : %d\n", item);
			        break;

			        default:
			        printf("Enter either 1 or 2\n");
			        break;
		        }
			break;
		
		        case 'C':
		        printf("Select stack 1 or 2 : ");
		        scanf("%d", &stk_choice);
		        switch(stk_choice)
		        {
			        case 1:
				printf("The elements in Stack-1 are : \n");
			        display(stk_choice);
				break;

				case 2:
				printf("The elements in Stack-2 are : \n");
				display(stk_choice);
				break;

				default:
				printf("Enter either 1 or 2\n");
				break;
			}
			break;

			default:
			printf("Enter either A or B or C\n");
			break;
		}
	}
}

void push1(int item)
{
	if (top1 == (MAX-1)/2)
	{
		printf("Stack is Full.\n");
	}
	else
	{
		top1 = top1 + 1;
		arr[top1] = item;
	}
}

void push2(int item)
{
	if(top2 == MAX/2)
	{
		printf("Stack is Full.\n");
	}
	else
	{
		top2 = top2 - 1;
		arr[top2] = item;
	}
}

int pop1()
{
	int tmp;
	if(top1 == -1)
	{
		printf("Stack-A is Empty.\n");
		return 0;
	}
	else
	{
		tmp = arr[top1];
		top1 = top1 -1;
		return tmp;
	}
}


int pop2()
{
	int tmp;
	if(top2 == MAX)
	{
		printf("Stack-B is Empty.\n");
		return 0;
	}
	else
	{
		tmp = arr[top2];
		top2 = top2 + 1;
		return tmp;
	}
}

void display(int stk_choice)
{
	int j;
	if(stk_choice == 1)
	{
		for(j = 0; j <=(MAX -1)/2 ; j++)
		{
			printf("%d\n", arr[j]);
		}
	}
	else if(stk_choice == 2)
	{
		for(j = MAX-1; j >= MAX/2; j--)
		{
			printf("%d\n", arr[j]);
		}
	}
}

