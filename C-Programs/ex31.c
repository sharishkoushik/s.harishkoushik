/* Binary Search Tree */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
struct node 
{
	struct node *lchild;
	int data;
	struct node *rchild;
};

typedef struct node node;

struct node *create_tree(struct node *, int);
void preorder(node *);
void push(node *);
node *pop();
int is_stackempty();
void n_preorder(node *);
int height_tree(node *);
void del_tree(node *root);
void ancesstors(node *root, int item);
void root_to_leaf(node *);
void push_stack(int);
int pop_stack();
int is_tmpstackempty();

node *stack[MAX];
int tmp_stack[MAX];
int top = -1;
int top_stack = -1;
int count = 0;
int leaf_count = 0;

int main(void)
{
	struct node *root;
	root = NULL;
	int n,height;
	printf("Enter the number of elements in the tree : ");
	scanf("%d", &n);
	root = create_tree(root, n);
	//printf("Preorder traversal of the tree .... \n");
	//preorder(root);
	//printf("\n");
	//printf("Non-recursive Preorder traversal of the tree .... \n");
	//n_preorder(root);
	//printf("\n");
	//height = height_tree(root);
	//printf("Height of the tree is : %d\n", height);
	//del_tree(root);
	//ancesstors(root, 6);
	root_to_leaf(root);
	return 0;
}

struct node *create_tree(struct node *root, int n)
{
	struct node *ptr, *tmp, *par;
	ptr = root;
	int i, ikey;
	printf("Enter the elements in the tree : \n");
	for(i = 0 ; i< n ; i++)
	{
		scanf("%d", &ikey);
		if(ptr == NULL && i == 0)
		{
			tmp = (struct node *)malloc(sizeof(struct node));
			tmp -> data = ikey;
			tmp -> lchild = NULL;
			tmp -> rchild = NULL;
			root = tmp;
		}
		else
		{
			ptr = root;
			while(ptr != NULL){
			par = ptr;
			if(ikey < ptr -> data)
			{
				ptr = ptr -> lchild;
			}
			else if(ikey > ptr -> data)
			{
				ptr = ptr -> rchild;
			}
			else
			{
				printf("Duplicate key\n");
				return root;
			}
			}
			tmp = (node *)malloc(sizeof(node));
			tmp -> data = ikey;
			tmp -> lchild = NULL;
			tmp -> rchild = NULL;
			if (ikey < par -> data)
			{
				par -> lchild = tmp;
			}
			else if(ikey > par -> data)
			{
				par -> rchild = tmp;
			}
		}
	}
	return root;
}

void preorder(node *root)
{
	node *ptr;
	ptr = root;
	if(ptr == NULL)
		return;
	printf("%d ", ptr -> data);
	preorder(ptr -> lchild);
	preorder(ptr -> rchild);
}

void push(node *item)
{
	if(top == (MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top + 1;
	stack[top] = item;
}

node *pop()
{
	node *item;
	if(top == -1)
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	item = stack[top];
	top = top - 1;
	return item;
}

int is_stackempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void n_preorder(node *root)
{
	node *ptr;
	int leaf_arr[10], j = 0;
	ptr = root;
	if( ptr == NULL)
	{
		printf("Tree is Empty\n");
		return ;
	}
	push(ptr);
	while(!is_stackempty())
	{
		ptr = pop();
		count++;
		printf("%d ", ptr -> data);

		if(ptr -> rchild != NULL)
			push(ptr -> rchild);
		if (ptr -> lchild != NULL)
			push(ptr -> lchild);
		else if((ptr -> rchild == NULL) && (ptr -> lchild == NULL))
		{
			leaf_count++;
			leaf_arr[j] = ptr -> data;
			j++;
		}

	}
	printf("\n");
	printf("Size of the tree or the number of nodes in the tree is : %d\n", count);
	printf("Number of leaf nodes in the tree is : %d\n", leaf_count);
	printf("The elements of the leaf array is : \n");
	for(j = 0 ; j < 3; j++)
	{
		printf("%d ", leaf_arr[j]);
	}
	printf("\n");
}

int height_tree(node *root)
{
	int h_left, h_right;
	node *ptr;
	ptr = root;
	if(ptr == NULL)
	{
		return 0;
	}
	h_left = height_tree(ptr -> lchild);
	h_right = height_tree(ptr -> rchild);
	if (h_left > h_right)
	{
		return 1 + h_left;
	}
	else 
	{
		return 1 + h_right;
	}
}

void del_tree(node *root)
{
	node *ptr,*tmp;
	int leaf_arr[10], j = 0;
	ptr = root;
	if( ptr == NULL)
	{
		printf("Tree is Empty\n");
		return ;
	}
	push(ptr);
	while(!is_stackempty())
	{
		ptr = pop();
		if(ptr -> rchild != NULL)
			push(ptr -> rchild);
		if (ptr -> lchild != NULL)
			push(ptr -> lchild);
		free(ptr);
	}
	ptr = NULL;
	//printf("Root is %d\n", ptr -> data);
	//printf("ptr -> lchild -> data is : %d\n", ptr -> lchild -> data);
	//printf("ptr -> rchild -> data is : %d\n", ptr ->rchild -> data);
	if(ptr == NULL)
	{
		printf("Tree is destroyed\n");
		return;
	}

	printf("\n");
}

void ancesstors(node *root, int item)
{
	node *ptr;
	int arr[11] = {0,0,0,0,0,0,0,0,0,0,0}, j=0, height, size_arr;

	height = height_tree(root);
	ptr = root;
	if(ptr -> data == item)
	{
		printf("Match found at root and hence no ancesstors\n");
		return;
	}
	printf("Calculating the ancesstors of the item .....\n");
	while(ptr -> data != item && ptr != NULL)
	{
		if (item > ptr -> data)
		{
			arr[j] = ptr -> data;
			ptr = ptr -> rchild;
			j++;
		}
		else if(item < ptr -> data)
		{
			arr[j] = ptr -> data;
			ptr = ptr -> lchild;
			j++;
		}
	}
	printf("size_arr is : %d\n", size_arr);
	if(ptr -> data == item)
	{
		printf("The ancesstors are :");
		for(j =0 ; arr[j] != 0 ; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}

void push_stack(int item)
{
	if(top_stack == MAX)
	{
		printf("Stack Overflow....\n");
		exit(1);
	}
	top_stack = top_stack + 1;
	tmp_stack[top_stack] = item;
}

int pop_stack()
{
	int item;
	if(top_stack == -1)
	{
		printf("stack is empty...\n");
		exit(1);
	}
	item = tmp_stack[top_stack];
	top_stack --;
	return item;
}

int is_tmpstackempty()
{
	if (top == -1)
		return 1;
	else
		return 0;
}

void stack_items()
{
	int i;
	printf("Items in the staack are ...\n");
	for(i =0; i <= top; i++)
	{
		printf("%d ", tmp_stack[i]);
	}
	printf("\n");
}

void root_to_leaf(node *root)
{
	node *ptr;
	int item=0;
	do
	{
		ptr = root;
		while(ptr != NULL)
		{
			if(item == ptr -> data)
			{
				printf("%d ", ptr -> data);
				ptr = ptr -> rchild;
			}
			if(ptr -> rchild != NULL)
			{
				push_stack(ptr -> data);
			}
			printf("%d ", ptr -> data);
			ptr = ptr -> lchild;
		}
		//stack_items();
		printf("\n");
		item = pop_stack();
		//printf("Item popped is : %d\n", item);
	}while(is_tmpstackempty());
}

