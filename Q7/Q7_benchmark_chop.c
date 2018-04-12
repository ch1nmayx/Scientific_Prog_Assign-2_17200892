/****************************************************************
Name - Chinmay Sinha
Course - M.Sc Data and Computational Science
Module - Scientific Programming (ICHEC) (ACM40660)
College -- University College Dublin
****************************************************************/

// importing standard libraries

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>


// defining the randomarray function

int * randomarray( int n, int max) 
	{
	
	int i;
	// allocates the requested memory (n*sizeof(int)) and returns a pointer *arr
	int *arr =  (int*)malloc(n*sizeof(int));
	
	//using srand uses an integer value  as seed by the pseudo-random number generator algorithm.
	srand(1111);
	// in other words sets the starting point for producing a series of pseudo-random integers
	
	// looping through the entire size of the array (n)
	while (i < n) {
		
		// generating random numbers using the rand() function
		arr[i] = rand() % max+1;

		i++;
	}	

	return arr;
	
}


// Defining the recursive function bubble sort

void bubblesort(int arr[], int n)
{
	// temporary variable later used for swapping
	int t;
	
    // Base case
    if (n == 1)
        return;
 
    // Moving the largest element to other side
    for (int i=0; i<n-1; i++) 
	{
    
	// Checking for the condition if arr[i] is greater than arr[i+1]
		if (arr[i] > arr[i+1]) 
		{
			
		t = arr[i];                     //create new long variable t equal to value of arr[i]
		arr[i] = arr[i+1];           //update i index value to i + 1 value
		arr[i+1] = t;                  // Values SWAPPED
		
		}		
	}
	
    // recursive call for the remaining array
    bubblesort(arr, n-1);
}

   
// Defining chopsearch function
// This function assumes that the array is sorted in ascending order

int chopsearch(int i, int n, int arr[], int amin, int amax )
{
	int k;
	int x = amin + (amax - amin)/2;
		
	// the function will call itself on the ’left’ half of the array, bounded by min
	// and x (or return −1 if that half is empty)
   if (i < arr[x] ) 
	   {
		   // Checking for the empty array
		   if (amin >= x) {return -1;}
		   
		   else {return chopsearch(i,n,arr, amin, x-1);}			 
		}
	
	// the function will call itself on the ’right’ half of the array, bounded by x
	// and max (or return −1 if that half is empty)	
   if (i > arr[x] ) 
	   {
		   // Checking for the empty array
		   if (amin >= x) {return -1;}
		   
		   else {return chopsearch(i,n,arr, x+1, amax);}			 
		}
	
	
	// the function should iterate over elements ahead of x until it finds the lowest
	// array index containing the value i	
	if (i = arr[x] ) 
	{		   
		// loop through the remaining array
		for(k=x; k<=n-1; k++) 
		{
			if (arr[k] == i) return k; 
		}
	}
	
}
 

/***************************************************************************

											BENCHMARK CHOP FUNCTION
											====================

****************************************************************************/

// Defining the benchmark chop function 

double benchmark_chop(int n, int max, int s, int mult) {

int i ;
int *a;
time_t tst, tend;

// Start the timer
tst = time(0);

// Loop for mult times
for (int p = 0; p < mult; p++){
	
	// loop for 1000 cycles
	for (int q = 0; q <= 1000; q++){
		
		// generate an array through randomarray() using n and max as parameters
		a = randomarray(n,max);
		
		// sort the array through bubblesort()
		bubblesort(a,n);
		
		// search multiple times for the value s in the array using search(s, n, arr)
		int index = chopsearch(s, n, a, 0, n-1);
			
	}

}
	
// Stop the timer
tend = time(0);

// Deallocate the array,
free(a);

// Calculating the time difference 
double time_diff  = difftime(tend, tst);

// returning the above time difference which gives us the run-time (elapsed time)
return time_diff;

}


// MAIN FUNCTION

int main() {
	
	// Testing the following set of parameters
	int iter1Time = benchmark_chop (2000, 10000, 10, 2);
	printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("For the parameters - (2000, 10000, 10, 1)\n");
	printf("Total Time elapsed is %d seconds .....\n\n", iter1Time);
	
    // int iter1Time = benchmark_chop (2000, 10000, 10, 1000000);
	// printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	// printf("For the parameters - (2000, 10000, 10, 1000000)\n");
	// printf("Total Time elapsed is %d seconds .....\n\n", iter1Time);
	
	// int iter2Time = benchmark_chop (2000, 10000, 5000, 1000000);
	// printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	// printf("For the parameters - (2000, 10000, 5000, 1000000)\n");
	// printf("Total Time elapsed is %d seconds .....\n\n", iter2Time);
	
	// int iter3Time = benchmark_chop (2000, 10000, 9000, 1000000);
	// printf("++++++++++++++++++++++++++++++++++++++++++++++\n");
	// printf("For the parameters - (2000, 10000, 9000, 1000000)\n");
	// printf("Total Time elapsed is %d seconds .....\n\n", iter3Time);
	
    return 0;
}



