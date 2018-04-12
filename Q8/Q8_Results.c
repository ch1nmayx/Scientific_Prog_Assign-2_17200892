/****************************************************************
Name - Chinmay Sinha
Course - M.Sc Data and Computational Science
Module - Scientific Programming (ICHEC) (ACM40660)
College -- University College Dublin
****************************************************************/

/***************************************************************************

										BENCHMARK NAIVE FUNCTION RESULTS
										==========================

****************************************************************************/

// SEARCH FUNCTION
int search(int i, int n, int arr[] ) 
{
	int loop; 
	
	// Assuming that the array is sorted in ascending order
	// Scanning the list from the beginning until it finds the correct element
	for(loop=0; loop<n; loop++) {
	
	if (arr[loop] == i) return loop;

	// if an element superior to i is found then break from loop and return -1
	if  (arr[loop] > i) break;
	
	} 

// if the correct element is not found or an element superior to i is found(the array being sorted, that means the element we’re looking for is not present) or the end of the array is reached then return -1
	return -1;
} 

// Complexity of the the search algorithm is O(n) -  as there is a single loop involved which executes till the end of the input array, hence, as we will inrease the input size by 1 , the execution will also increase linearly suggesting the O(n) complexity. Big O notation will always assume the upper limit where the algorithm will perform the maximum number of iterations.


/***************************************************************************

									BENCHMARK CHOP FUNCTION RESULTS
									==========================

****************************************************************************/

// CHOPSEARCH FUNCTION
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

// Complexity of the chopsearch algorithm is O(N log N) -  The bisection of data sets in chopsearch produces a growth curve that peaks at the beginning and slowly flattens out as the size of the data sets increase. Doubling the size of the input data set has little effect on its growth as after a single iteration of the algorithm the data set will be halved and therefore on a par with an input data set half the size and also we have the loop at i = arr[x] condition which will take longer to execute as we increase the input size


