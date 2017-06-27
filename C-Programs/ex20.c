/*Program to rsive function to find the sum of all even numbers in an array,
 reverse the array and check for ascending order in an array */
 
#include <stdio.h>

 int sym(int arr[], int index);
 void reverse_array(int arr[], int, int);
int ascending(int arr[], int, int );

 int main(void)
 {
	 int arr[10] , i, total, ass;
	 printf("Enter the elements in the array :\n");

	 for(i =0; i < 5 ; i++)
	 {
		 scanf("%d", &arr[i]);
	 }

	 /*total = sum(arr, 0);
	 printf("Toatal : %d\n", total);

	 printf("Reversing the array :\n");
	 reverse_array(arr, 0, 4);
	 printf("Elements in the array after reversing...\n");
	 for(i = 0 ; i< 5; i++)
	 {
		 printf("%d ", arr[i]);
	 }
	 printf("\n");*/

	 printf("Checking for ascending...\n");

	 ass = ascending(arr, 0,1) ? 0 : -1;

	 if( ass == 0 || ass ==1) printf("Array in ascending\n");
	 else printf("Not in ascending\n");


	 return 0;
 }

 int sum(int arr[], int index)
 {
	 int i=index,tmp;

	 printf("i : %d, arr[i] : %d\n", i, arr[i]);
	 if (i <  5)
	 {
	 
		 if(arr[i]%2 == 0)
		 {
			 //tmp = arr[i];
			 //i = i +1;
			 return (arr[i] + sum(arr, ++i));
		 }
		 else
		 {
			 return sum(arr, ++i);
		 }
         }
	 return 0;
 }

void reverse_array(int arr[], int i, int j)
{
	int tmp;
	if(i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] =tmp;
		i ++;
		j --;
		reverse_array(arr, i, j);
	}
}
	 
int ascending(int arr[], int i, int j)
{
	if(j <= 4)
	{
                //printf("i : %d, arr[i] : %d and j : %d, arr[j] : %d\n", i,arr[i],j,arr[j]);
		if (arr[i] < arr[j])
	        {
		        i++;
			j++;
			ascending(arr, i, j);
			return 1;
		}
		else 
			return -1;
	}
	return 0;
}




