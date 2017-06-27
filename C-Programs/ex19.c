#include <stdio.h>

#define ROWS 3
#define COL 3

void display(int mat[ROWS][COL]);
int main(void)
{
	int mat[ROWS][COL], i,j,k,tmp;
	printf("Enter the elements of the matrix : \n");
	for(i = 0; i< ROWS; i++)
	{
		for(j=0;j<COL;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	printf("The elements entered in the matrix are : \n");
	display(mat);

	printf("Sorting the rows of the matrix .... \n");
	for(i = 0; i<ROWS; i++)
	{
		for(j=0;j<COL;j++)
		{
			for(k =j+1 ; k < COL ; k++)
			{
				if(mat[i][j] > mat[i][k])
				{
					tmp = mat[i][j];
					mat[i][j] = mat[i][k];
					mat[i][k] = tmp;
				}
			}
		}
	}
	printf("Matrix after sorting is : \n");
	display(mat);

	printf("Interchanging the first and last row .... \n");
	for(i = 0, k =2; i<=0 && k<=2 ; i++, k--)
	{
		for(j = 0; j < COL; j++)
		{
			tmp = mat[i][j];
			mat[i][j] = mat[k][j];
			mat[k][j] = tmp;
		}
	}
	display(mat);
	
	printf("Reversing the rows of the matrix ....\n");
	for(i = 0, k =2; i< k ; i++, k--)
	{
		for(j = 0; j < COL; j++)
		{
			tmp = mat[i][j];
			mat[i][j] = mat[k][j];
			mat[k][j] = tmp;
		}
	}
	display(mat);
	return 0;
}

void display(int mat[3][3])
{

	int i,j;
	for(i = 0; i< 3; i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%5d",mat[i][j]);
		}
		printf("\n");
	}
}




