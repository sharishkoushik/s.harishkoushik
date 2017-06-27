#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct node {
	struct node *lchild;
	int data;
	struct node *rchild;
};
typedef struct node node;

int top = -1;
node *arr[MAX];

node *insert_element(node *root, int data);
int delete_ele(node *root, int data);
node *case_a(node *root, node *par, node *ptr);
node *case_b(node *root, node *par, node *ptr);
node *case_c(node *root, node *par, node *ptr);
int display_bt(node *root);
int push(node *);
node *pop();
void traverse_preorder(node *);

int main()
{
	node *root;
	root = NULL;
	root = insert_element(root,5);
	//printf("The inserted element is %d\n", 5);
	root = insert_element(root,10);
	//printf("root is %p\n", root);
	//printf("The inserted element is %d\n", 10);
	root = insert_element(root,15);
	//printf("root is %p\n", root);
	//printf("The inserted element is %d\n", 15);
	root = insert_element(root,20);
	//printf("root is %p\n", root);
	//printf("The inserted element is %d\n", 20);
	//display_bt(root);
	//delete_ele(root,20);
	//display_bt(root);
	traverse_preorder(root);
	return 0;
}

node *insert_element(node *root, int data)
{
	node *p, *par, *tmp;
	p = root;
	if(p == NULL)
	{
		tmp = (node *)malloc(sizeof(node));
		tmp -> data = data;
		tmp -> lchild = NULL;
		tmp -> rchild = NULL;
		root = tmp;
		return root;
	}
	else
	{
		while(p != NULL)
		{
			par = p;
			//printf("p is %d\n", p -> data);
	                //printf("par is %p\n", root);
			if(data > p -> data)
			{
				p = p -> rchild;
			}
			else if(data < p -> data)
			{
				p = p -> lchild;
			}
		}
		if (data > par -> data)
		{
			tmp = (node *)malloc(sizeof(node));
			tmp -> data = data;
			par -> rchild = tmp;
		}
		else if (data < par -> data)
		{
			tmp = (node *)malloc(sizeof(node));
			tmp -> data = data ;
			par -> lchild = tmp;
		}
	}
	return root;
}

int display_bt(node *p)
{
	if(p == NULL)
		return 0;
	printf("%d\n", p -> data);
	display_bt(p -> lchild);
	display_bt(p -> rchild);
	return 0;
}

int delete_ele(node *root, int data)
{
	node *p, *par;
	p = root;
	while(p != NULL)
	{
		if(data ==  p -> data)
		{
			break;
		}
		par = p;
		if(data < p -> data)
		{
			p = p -> lchild;
		}
		else if(data > p -> data)
		{
			p = p -> rchild;
		}
	}

	if(p -> lchild == NULL && p ->rchild == NULL)
	{
		root = case_a(root, par, p);
	}
	else if(p -> lchild == NULL)
	{
		root = case_b(root, par, p);
	}
	else if(p -> rchild == NULL)
	{
		root = case_b(root, par, p);
	}
	else
	{
		root = case_c(root, par, p);
	}
	return 0;
}

node *case_a(node *root, node *par, node *ptr)
{
	if(par -> lchild == ptr)
	{
		par -> lchild = NULL;
		free(ptr);
	}
	else
	{
		par -> rchild = NULL;
		free(ptr);
	}
	return root;
}

node *case_b(node *root, node *par, node *ptr)
{
	node *child;
	if(ptr -> lchild != NULL)
	{
		child = ptr -> lchild;
	}
	else
	{
		child = ptr -> rchild;
	}
	if (par -> lchild == ptr)
	{
		par -> lchild = child;
		free(ptr);
	}
	else
	{
		par -> rchild = child;
		free(ptr);
	}
	return root;
}

node *case_c(node *root, node *par, node *ptr)
{
	node *parsucc, *succ; 
	parsucc = ptr;
	succ = ptr -> rchild;
	while(succ -> lchild != NULL)
	{
		parsucc = succ;
		succ = succ -> lchild;
	}
	ptr -> data = succ -> data;
	if (ptr -> lchild == NULL && ptr -> rchild == NULL)
		case_a(root, parsucc, succ);
	else
		case_b(root, parsucc, succ);
	return root;
}

int push(node *ptr)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	top = top + 1;
	arr[top] = ptr;
}

node *pop()
{
	node *tmp;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	tmp = arr[top];
	top = top -1;
	return tmp;
}

void traverse_preorder(node *root)
{
	node *tmp, *ptr;
	ptr = root;
	if (ptr == NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	push(ptr);
	while(ptr != NULL)
	{
		ptr = pop();
		printf("%d\n", ptr -> data);
		if (ptr -> rchild != NULL)
			push(ptr -> rchild);
		if (ptr -> lchild != NULL)
			ptr = ptr -> lchild;
	}
	printf("\n");
}
