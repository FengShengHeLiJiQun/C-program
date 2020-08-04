/*******************************************************************************
* Copyright Statement: Wingtech inc.
*
*******************************************************************************/
/*******************************************************************************
* Filename:
*	Sorting algorithm
*Description:
*	This file contains several commonly used sorting algorithms
*Author:
	Qiu Haohao
*Time:
	2020.8.1
********************************************************************************/

/*******************************************************************************
* Include
*******************************************************************************/

#include <stdio.h>
#include <time.h>
//#include <malloc.h>


/*******************************************************************************
* Global Function
*******************************************************************************/

void SelectSort(int a[]);
void BubbleSort (int a[]);
void QuickSort( int a[] , int left, int right);
void MergeSort(int a[], int n);
//The names of arrays and general variables cannot be the same.
void Merge(int a[], int L[], int R[], int l, int r);
//When step = 1, that's the general interpolation algorithm.
int InterpolationSortPlus(int a[], int n, int step);
int ShellSort(int a[], int n);
void CounterSort(int a[], int n);

/*******************************************************************************
* Global Variable
*******************************************************************************/

time_t start, end;

int main()
{
	//Defines an array to hold the retrieved numbers.
 	int i,a[10];
	printf("Please enter 10 numbers£º\n");	
	for (i = 0; i <= 9; i ++)
		scanf("%d", &a[i]);
	
	//start and end are used to measure the time used by the sorting algorithm.
	start = clock();

	//Call the sorting algorithm function.
	//SelectSort( a);
	//BubbleSort ( a);
	//QuickSort( a, 0,9);
	//MergeSort( a, 10);
	//InterpolationSortPlus( a, 10, 1);
        	//ShellSort( a,10);
	CounterSort(a, 10);


	end = clock();

	
	//Output sorting result.
	printf("The order from small to large is £º\n");
	for (i = 0; i <= 9; i ++)
		printf("%d  ",a[i]);
	printf("\nThis line shows how long each cycle has run: %f ms\n",difftime(end, start));
				
   return 0;
}



/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	select  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*RETURNS
*	void
*****************
*******************************************************************************/

void SelectSort( int a[])
{
	int i, j, x;
	for (i = 0; i <= 9; i ++)
		for (j = i + 1;  j <= 10;  j ++)
			if (a[i] > a[j])
			{
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	return a;
}

/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	bubble  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*RETURNS
*	void
*****************
*******************************************************************************/

void BubbleSort (int a[])
{
	int i, j, x;
	for (i = 0; i <= 9; i ++)
		for (j = 0;  j < 9 - i;  j ++)
			if (a[j] > a[j + 1])
				{
				x = a[j];
				a[j] = a[j + 1];
				a[j + 1] = x;
				}
	return a;
}

/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	quick  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*	left	[IN]	the left boundary of a
*	right	[IN]	the right boundary of a
*RETURNS
*	void
*****************
*******************************************************************************/

void QuickSort (int a[], int left, int right)
{
	int i, j, x;
	i = left;
	j = right;
	x = a[left];
	if (left >= right)
	{
		return a;
	}
	while(i < j)
	{
		while(i < j && x <= a[j])
		{
			j --;
		}
		a[i] = a[j];
		while(i < j && x >= a[i])
		{
			i ++;
		}
		a[j] = a[i];
	}
	a[i] = x;
	QuickSort (a, left, i - 1);
	QuickSort (a, i + 1, right);
	return a;
}


/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	merge  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*	L[]	[IN]	subsequence
*	R[]	[IN]	subsequence
*	l	[IN]	length of L[]
*	r	[IN]	lengtn of R[]
*	n	[IN]	length of a[]
*RETURNS
*	void
*****************
*******************************************************************************/

//Two ordered sequences L and R are merged into a,
//r and l are the length of R and L.
void Merge(int a[], int L[], int R[], int l, int r)
{
	int i= 0,j = 0,k = 0;
	//The elements of the two subsequences are compared inturn,
	//and the smaller ones are taken out and put into a.
	while(i < l && j < r)
	{
		if(L[i] <= R[j])
			a[k++] = L[i++];
		else
			a[k++] = R[j++];
	}
	//Merge the remanining elements on the left into a.
	while(i < l)
	{
		a[k++] = L[i++];
	}
	//Merge the remaining elements on the right into a.
	while(j < r)
	{
		a[k++] = R[j++];
	}
}

//Recursive body
void MergeSort(int a[],int n)
{
	if(n > 1)
	{
		int mid = n / 2;
		int i, j;
		//Allocate memory to the left and right arrays.
		//int *left = (int*)malloc(sizeof(int) * mid);
		//int *right = (int*)malloc(sizeof(int) * (n - mid));
		int left[mid];
		int right[n - mid];
		//Assign values to the left and right arrays.
		for(i = 0; i < mid; i++)
			left[i] = a[i];
		for(j = mid; j < n; j++)
			right[j] = a[j];
		//Recursion continues on the left and right arrays.
		MergeSort(left,mid);
		MergeSort(right,n - mid);
		//Merge two arrays.
		Merge(a,left,right,mid,n - mid);
		//free(left);	//Free memory
		//free(right);
	}
	return a;
}

/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	interpolation sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*	n	[IN]	length of a
*	step	[IN]	interval
*RETURNS
*	void
*****************
*******************************************************************************/

//Step size can be spacified for improved version InterpolationSort.
int InterpolationSortPlus(int a[], int n ,int step)
{
	int i, j;

	for (i = step; i < n; i++)
	{
		//compare the inserted values step by step forward.
		for (j = i; j >= step  && a[j] < a[j - step]; j -= step)	
		{
			int x = 0;
			x = a[j];
			a[j] = a[j - step];
			a[j - step] = x;
		}
	}
	return a;
}

/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	shell  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*	n	[IN]	length of a
*RETURNS
*	void
*****************
*******************************************************************************/

//Shell sort calls InterpolationSortPlus.
int ShellSort(int a[], int n)
{
	int step;	//Set a step size.
	for (step = n / 2;  step >0 ;  step /= 2)
	{	
		printf("%d \n", step);
		InterpolationSortPlus(a, n, step);
		for (int i = 0; i < 10; i ++)
                		printf("%d  ",a[i]);    //Output the sorted results.
		printf("\n");
	}
	return a;
}



void CounterSort(int a[], int n)
{ 
	int max, min, i;
	for ( i = 1; i < array.length; i++) 
	{
            		if (array[i] > max)
		 {
                		max = array[i];
           		 }
            		if(array[i] < min)
		 {
                		min = array[i];
           		 }
       	 }
	int d = max - min;
	int c[d + 1];
	for ( i = 0; i < d +1; i ++)
		c[i] = 0;
	for ( i = 0; i < n; i++)
	 {
            		c[array[i] - min]++;
       	 }
	
	for (i = 0; i < d + 1; i ++£©
	{
		int j = 0;
		if (c[i] > 0)
		{
			for ( j = j ; j < j + c[i]£»j++)
				a[j] = c[i] +min;
		}
	}
	return a;
}

			
/*******************************************************************************
*****************
* FUNCTION
*	sort
*DESCRIPTION
*	counter  sort
*PARAMETERS
*	a[]	[IN]	the sort object 
*	n	[IN]	length of a
*RETURNS
*	void
*****************
*******************************************************************************/			

void CounterSort(int a[], int n)
{ 

	//The maximum and minimum values of the sequence are obtained
	//and the differential value d is calculated.
	int max, min, i, d;
	max = a[0];
	min = a[0];
	for ( i = 1; i < n; i++) 
	{
            		if (a[i] > max)
		 {
                		max = a[i];
           		 }
            		if(a[i] < min)
		 {
                		min = a[i];
           		 }
       	 }
	d = max - min;

	//Create and initializes an array of size d.
	int *c = (int*)malloc(sizeof(int) * (d + 1));
	for ( i = 0; i < d +1; i ++)
	{
		c[i] = 0;
	}
	
	//count the number of corresponding indexes.
	for ( i = 0; i < n; i++)
	 {
            		c[a[i] - min] = c[a[i] - min] + 1;
       	 }

	//Assign value in turn according to statistical quantities.
	for (i =0; i < n; )
		for (int j = 0; j < d +1; j ++)
		{
			if (c[j] > 0)
			{
				for ( int t = 0; t < c[j]; t ++)
				{
					a[i] = j + min;
					i ++;
				}
			}
		}
	
	free(c);
	return a;
}
	