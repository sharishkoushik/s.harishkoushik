#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *insert_element(struct node *start, int data);
int display_ll(struct node *start);
int main()
{
	struct node *start;
	start = NULL;
	start = insert_element(start, 5);
	printf("Address of start is %p\n", start);
	start = insert_element(start, 10);
	printf("Address of start is %p\n", start);
	start = insert_element(start, 15);
	printf("Address of start is %p\n", start);
	start = insert_element(start, 20);
	printf("Address of start is %p\n", start);
	display_ll(start);
	return 0;
}

struct node *insert_element(struct node *start, int data)
{
	struct node *tmp, *p;
	p =start; 
	if(p == NULL)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> data = data;
		tmp -> link = NULL;
		start = tmp;
		return start ;
	}
	else
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp -> data = data;
                tmp -> link = p;
		start = tmp;
		return start;
	}
}


int display_ll(struct node *start)
{
        struct node *p;
	p = start;
	printf("The elements in the linked list are : \n");
	while( p != NULL)
	{
		printf("Address is %p, Data is %d\n", p, p -> data);
		p = p -> link;
	}
	return 0;
}
