/* Program to reverse a stack using a queue*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *link;
}

typdef struct node node;
node *q1, *q2, *root;
q1 = NULL q2= NULL;

void enqueue(node *, int );
void dequque();
int main()
{
	enqueue(q2, 5);
	enqueue(q3, 6);
	enqueue(q4, 7);
	dequeue();
	dequeue();
	dequeue();
}

void enqueue(node *q2, int data)
{
	node *tmp;
	tmp = (node *)malloc(sizeof(node));
	if(tmp == NULL)
	{
		printf("Memory is full\n");
		exit(1);
	}
	tmp -> info = data;
	tmp -> link =NULL;
	if(q1 == NULL && q2 == NULL)
	{
		q1 = tmp;
		q2 = tmp;
		root = tmp;
	}
	else
	{
		 q2 -> link = tmp;
		 q2 = tmp;
	}
}




