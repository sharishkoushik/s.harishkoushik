/* Program to implement a stack using two queues */

#include <stdio.h>
#include <stdlib.h>

struct queue
{
	int info;
	struct queue *link;
};

typedef struct queue queue;

queue *q1=NULL; 
queue *q2=NULL;

queue *enqueue(queue *, int);
int dequeue(queue*);
void insert(int);
void delete();

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
			insert(item);
			break;

			case 2 :
			delete();
			break;

			/*case 3 :
			printf("The elements in the queue are : \n");
			display(q1, q2);
			break;*/

			default:
			printf(" Wrong Choice! \n");
			break;
		}
	}
}

void insert(int item)
{
	q1 = enqueue(q1, item);
}

void delete()
{
	int x;

	x = dequeue(q1);
	q2 = enqueue(q2, x);
	if(q1 == NULL)
	{
		dequeue(q2);
	}
	else
	{
		printf("First empty the q1.\n");
	}
}

queue *enqueue(queue *xx, int item)
{
	queue *tmp, *front, *rear;
	tmp = (queue *)malloc(sizeof(queue));
	if(tmp == NULL)
	{
		printf("Out of Memory.\n");
		return ;
	}
	tmp -> info = item;
	if(xx == NULL)
	{
		tmp -> link = xx;
		xx = tmp;
		front = tmp;
	}
	else
	{
		rear -> link = tmp ;
	}
	rear = tmp;
	return xx;

}

int dequeue(queue *q1)
{
	int x;
	queue *tmp;
	if(q1 == NULL)
	{
		printf("Queue is empty.\n");
		return;
	}
	tmp = q1;
	x = tmp -> info;
	q1 = tmp -> link;
	free(tmp);
	return x;
}
