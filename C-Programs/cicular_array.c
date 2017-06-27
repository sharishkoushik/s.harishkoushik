#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void enqueue(int item);
int dequeue();
void display();

int front = 0, rear = 0;
int q[MAX];

int main()
{
	int i;
	enqueue(5);
	enqueue(10);
	enqueue(15);
	enqueue(20);
	enqueue(25);
	enqueue(30);
	display();
	/*i = dequeue();
	printf("i : %d\n", i);
	display();
	i = dequeue();
	printf("i : %d\n", i);
	i = dequeue();
	printf("i : %d\n", i);
	display();*/
	return 0;
}

void enqueue(int item)
{
	rear = (rear + 1)%MAX;
	if(front == rear)
	{
		printf("Q is full\n");
		if(rear == 0)
			rear = MAX - 1;
		else 
			rear = rear - 1;
	}
	else
	{
		q[rear] = item;
	}
	return;
}

void display()
{
	int i;
	printf("Displaying the elements of the queue ....\n");
	for(i = front ; i<= rear ; i++)
	{
		printf("%d\n",q[i]);
	}
	printf("-------\n");
}

int dequeue()
{
	int item;
	if(front == rear)
	{
		printf("Q is empty\n");
		exit(1);
	}
	else
	{
		front = (front + 1)%MAX;
		item = q[front];
		return item;
	}
}
