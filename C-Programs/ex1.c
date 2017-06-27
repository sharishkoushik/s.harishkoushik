/*Program to count the number of occurences of an element in a single linked list*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node node;

node *create_ll(node *);
int display_ll(node *);
int count_occurences(node *);
int small_large(node *start);
node *create_copy_of_ll(node * , node *);
node *reverse_ll(node *);
int swap_adjacent_exchanging_info(node *);
node *swap_adjacent_exchanging_link(node *);
int move_largest_to_last(node *);
int DeleteDuplicates(node *);
int intersection(node *, node *);
int nth_node_from_last(node *);
int new_reverse(node *);

int main()
{
	node *start, *start2;
	int choice;
	start = NULL, start2 = NULL;
	start = create_ll(start);
	printf("Enter choice between 0 and 11: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 0:
		df:display_ll(start);
		break;
		case 1:
	        count_occurences(start);
		break;
		case 2:
	        small_large(start);
		break;
		case 3:
		start2 = create_copy_of_ll(start, start2);
		display_ll(start2);
		break;
		case 4:
		start = reverse_ll(start);
                display_ll(start);
		break;
		case 5:
		swap_adjacent_exchanging_info(start);
		display_ll(start);
		break;
		case 6:
		start = swap_adjacent_exchanging_link(start);
		display_ll(start);
		break;
		case 7:
		move_largest_to_last(start);
		display_ll(start);
		break;
		case 8:
		DeleteDuplicates(start);
		display_ll(start);
		break;
		case 9:
		start2 = create_ll(start2);
		intersection(start, start2);
		break;
		case 10:
		nth_node_from_last(start);
		break;
		case 11:
		new_reverse(start);
		break;
		default :
		printf("Not a valid choice and hence executing the default choice\n");
		goto df;
	}
	return 0;
}

node *create_ll(node *start)
{
	node *tmp, *p;
	int n, i, num;
	printf("Enter the number of elements in the linked list : ");
	scanf("%d", &n);
	printf("Enter the elements in the linkedlist: \n");
	for( i = 0 ; i < n ; i++)
	{
		scanf("%d", &num);
		if(start == NULL)
		{
			tmp = (node *)malloc(sizeof(node));
			tmp -> info = num;
			tmp -> link = NULL;
			start = tmp;
		}
		else
		{
			p = start;
			while( p -> link != NULL)
			{
				p = p -> link;
			}
			tmp = (node *)malloc(sizeof(node));
			tmp -> info = num;
			tmp -> link = NULL;
			p -> link =tmp;
		}
	}
	return start;
}

int display_ll(node *start)
{
        node *p;
	p = start;
	printf("The elements in the linked list are : \n");
	while( p != NULL)
	{
		printf("%d\n", p -> info);
		p = p -> link;
	}
	return 0;
}

int count_occurences(node *start)
{
        int num;
	printf("Enter a number to find the number occurences in the linked list : ");
	scanf("%d", &num);
	node *p=start;
	int occ=0;

	if( p == NULL)
	{
		printf("The list is empty");
	}
	while( p != NULL)
	{
		if( p -> info == num)
		{
			occ = occ + 1;
		}
		p = p -> link;
	}

	if ( occ == 0)
	{
		printf(" The given number %d is not present in the linked list. \n", num);
	}
	else
	{
		printf("The number of occurence of %d in the linked list is : %d\n", num, occ);
	}
	return 0;
}

int small_large(node *start)
{
	node *p, *q, *tmp;
	int small, large;
	for(p = start , q = p -> link ; q != NULL ; )
	{
		if ( p -> info <= q -> info )
		{
			small = p -> info;
			q = q -> link;
		}
		else if ( p -> info >  q -> info)
		{
			small = q -> info;
			p = q;
			q = q -> link;
		}
	}
	printf("The smallest element in the linkedlist is : %d\n", small);
	for(p = start , q = p -> link ; q != NULL ; )
	{
		if ( p -> info >= q -> info )
		{
			large = p -> info;
			q = q -> link;
		}
		else if ( p -> info <  q -> info)
		{
			large = q -> info;
			p = q;
			q = q -> link;
		}
	}
	printf("The largest element in the linkedlist is : %d\n", large);
	return 0;
}

node *create_copy_of_ll(node *start, node *start2)
{
	node *p, *q, *tmp;
	p = start, q = start2;
	while( p != NULL)
	{
		if(start2 == NULL)
		{
			tmp = (node *)malloc(sizeof(node));
			tmp -> info = p -> info;
			tmp -> link = NULL;
			start2 = tmp;
		}
		else
		{
			q = start2;
			while( q -> link != NULL)
			{
				q = q -> link;
			}
			tmp = (node *)malloc(sizeof(node));
			tmp -> info = p -> info;
			q -> link = tmp;
		}
		p = p -> link;
	}
	return start2;
}

node *reverse_ll(node *start)
{
	node *p, *prev, *next;
	p = start;
	prev = NULL;
	while ( p != NULL)
	{
		next = p -> link;
		p -> link = prev;
		prev = p;
		p = next;
	}
	start = prev;
	return start;
}

int swap_adjacent_exchanging_info(node *start)
{
	node *p, *q;
	int tmp;
	p = start, q = p -> link;
	while( q != NULL)
	{
		tmp = p -> info;
		p -> info = q -> info;
		q -> info =tmp;
		p = q -> link;
		q = q -> link -> link;
		if ( q -> link == NULL)
		        tmp = p -> info;
		        p -> info = q -> info;
		        q -> info =tmp;
			q = q -> link;
	}
	return 0;
}

node *swap_adjacent_exchanging_link(node *start)
{
	node *p, *q, *r, *tmp;
	if(start == NULL || start -> link==NULL)
		printf("This is a empty linked list.\n");
	r=p = start;
	while(p -> link != NULL)
	{
		q = p -> link;
		p -> link = q -> link ;
		q -> link = p;
		if ( p != start )
			r -> link = q;
		else
			start = q;
		r = p;
		if(p -> link != NULL)
		        p = p -> link;
	}
	return start;
}

int move_largest_to_last(node *start)
{
	node *p,*q;
	int tmp;
	p = start, q=p->link;
	while(q != NULL)
	{
		if(p -> info > q -> info)
		{
			tmp = p -> info;
			p -> info = q -> info;
			q -> info = tmp;
			p = p -> link;
			q = q -> link;
		}
		else
		{
			p = p -> link;
			q = q -> link;
		}
	}
	printf("The largest element in the linked list is : %d\n", p -> info);
	return 0;
}

int DeleteDuplicates(node *start)
{
        struct node *p, *q,*tmp;
	p=start; 
		   
	while(p!=NULL) 
	{ 
		q = p -> link, tmp = p; 
		while(q != NULL) 
		{ 
	 	        if(p->info == q->info) 
			{ 
			        tmp -> link =q->link; 
				q  =q->link; 
			}
			else 
			{
				tmp = q;
				q = q->link; 
			}
		}
		p=p->link; 
	}
	return 0;
}/*End of DeleteDuplicates()*/  

int intersection(node *start, node *start2)
{
	node *p, *q, *tmp, *r, *start3;
	p = start, q = start2, start3 = NULL, r = start3;
	printf("The elements of the first linked list is : \n");
	display_ll(start);
	printf("THe elements of the second linked list is : \n");
	display_ll(start2);
	while (p != NULL)
	{
		while ( q != NULL)
		{
		        if( p -> info == q -> info)
		        {
			        if ( start3 == NULL)
			        {
				        tmp = (node *)malloc(sizeof(node));
				        tmp -> info = p -> info;
				        tmp -> link = NULL;
				        r = tmp;
			 	        start3 = r;
			        }
			        else
			        {
				        while( r -> link != NULL)
					        r = r -> link;
				        tmp = (node *)malloc(sizeof(node));
				        tmp -> info = p -> info;
				        tmp -> link = NULL;
				        r -> link = tmp;
				        r = r -> link;
			        }
			        q = q -> link;
		        }
		        else
		        {
			        q = q -> link;
		        }
                }
		q = start2;
		p = p-> link;
	}
        printf("The intersection of two linked lists is : \n");
	DeleteDuplicates(start3);
        display_ll(start3);
	return 0;
}

int nth_node_from_last(node *start)
{
	node *p, *q;
	int n, count = 1;
	printf("Enter nth node from last : ");
	scanf("%d", &n);
	p = start;
	while( p -> link != NULL)
	{
		if (count < n)
		{
			count++;
		}
		else if (count == n)
		{
			q = start;
			count ++;
		}
		else if (count > n)
		{
			q = q -> link;
		}
		p = p -> link;
		if (p -> link == NULL)
		{
			printf("nth node from last is %d\n", q -> info);
		}
	}
	return 0;
}

int new_reverse(node *start)
{
	node *p,*q,*tmp,*tmp_link;
	p = start, q = start;
	while(p != NULL)
	{
		tmp = p ;
		tmp_link = p -> link;
		if(p == start)
		{
			p -> link = NULL;
		}
		else if (p -> link == NULL)
		{
			start = p;
			p -> link = q;
			break;
		}
		else 
		{
			p -> link = q;
		}
		q = p;
		p = tmp_link;
	}
	display_ll(start);
}
