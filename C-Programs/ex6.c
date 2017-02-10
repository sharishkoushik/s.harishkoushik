/* Program to implement a queue using two stacks */

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int info;
	struct node *link;
};

typedef struct node node ;

node *s1=NULL, *s2=NULL;

struct queue
{
	node *s1;
	node *s2;
}a;

typedef struct queue queue;

queue *q = &a;


void enqueue(int);
void dequeue();
node *push(node *, int);
int pop(node *);
void display(node *, node *);

int main()
{

	int item, choice;
        while(1)
	{
		printf("1. Enqueue\n");
		printf("2. Dequeue\n");
		printf("3. Display\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : 
			printf("Enter the item in the queue : ");
			scanf("%d", &item);
			enqueue(item);
			break;

			case 2 :
			dequeue();
			break;

			case 3 :
			printf("The elements in the queue are : \n");
			display(s1, s2);
			break;

			default:
			printf(" Wrong Choice! \n");
			break;
		}
	}
}

void enqueue(int x)
{
	q -> s1 = push(q -> s1,x);
}

void dequeue()
{
	int x; node *tmp= q -> s1;
	if (q -> s1 == NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		
		
		x = pop(q -> s1);
		q -> s2 = push(q -> s2, x);
		q -> s1 = tmp -> link;
		free(tmp);
		
		x = pop(q -> s2);
		printf("The popped element is : %d\n", x);
	}
}

node *push(node *xx, int data)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	if(tmp == NULL)
	{
		printf("Stack Overflow\n");
	}
	tmp -> info = data;
	tmp -> link = xx;
	xx = tmp;
	return xx;
}

int pop(node *yy)
{
	int buff;
	if(yy == NULL)
		printf("Queue is Empty\n");
	buff = yy -> info;
	return buff;
}

void display(node *s1, node *s2)
{
	node *tmp1, *tmp2;
	tmp1 = q -> s1, tmp2 = q -> s2;
	printf("The elements in s1 : \n");
	while (tmp1 != NULL)
	{
		printf("%d\n", tmp1 -> info);
		tmp1 = tmp1 -> link;
	}

	printf("The elements in s2 : \n");
	while (tmp2 != NULL)
	{
		printf("%d", tmp2 -> info);
		tmp2 = tmp2 -> link;
	}
}

