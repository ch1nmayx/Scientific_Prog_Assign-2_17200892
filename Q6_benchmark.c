#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>


int * randomarray( int n, int max) {
	int i;
	int *arr =  (int*)malloc(n*sizeof(int));
	
	//Uses system time to seed a proper random number.
	srand(1001);
	//rand() generates a random integer
	
	while (i < n) {
		arr[i] = rand() % max+1;
	//	printf("%d ",arr[i]);
		i++;
	}	
	return arr;
	
}


//TODO:Write a function bubblesort()
void bubblesort(int *list, int N) {
  int i, d, t;
  for (i = 0 ; i < (N - 1); i++) {        //array of entered integers
    for (d = 0 ; d < (N - i - 1); d++) {  //d array is one smaller than c
  //      printf("%d",list[i]);
		if (list[d] > list[d+1]) {            //if value "d" is greater than "d + 1"
        /* Bubble swap */
        t = list[d];                     //create new long variable t equal to value of list[d]
        list[d] = list[d+1];             //update d value to d + 1 value
        list[d+1] = t;                   //
        }
       }
      }
   }

   
 /* Recursive function to search x in arr[l..r] */
int search(int i, int n, int arr[] ) 
{
	int k; 
	
	/* loop through entire array */
	for(k=0; k<n; k++) {
	
	/* if this element contains the value being searched for, 
	* return the location in the array 
	*/
	
	if (arr[k] == i) return k;
	if  (arr[k] > i) break;
} 

/* if we went through the entire array and couldn't find 
* the element, return -1. as 0 is the smallest index in 
* the array, -1 represents an error and tells the calling 
* function that a value wasn't found
*/
return -1;
} 


int benchmark_naive(int n, int max, int s, int mult) {

int i ;
int *a;
time_t tst, tend;
clock_t cst, cend;
tst = time(0);
cst = clock();


for (int p = 0; p < mult; p++){
	for (int q = 0; q <= 1000; q++){
		
		a = randomarray(n,max);
		
		bubblesort(a,n);
		
		int index = search(s, n, a);
			
	}
}
	
tend = time(0);
cend = clock();

free(a);

int time_diff  = difftime(tend, tst);

return time_diff;
//printf("Elapsed: %ld\n", cend-cst);
}


int main() {
		
    int iter1Time = benchmark_naive (2000, 10000, 10, 1000000);
	printf("Total Time elapsed is %d", iter1Time);
	
	int iter2Time = benchmark_naive (2000, 10000, 5000, 1000000);
	printf("Total Time elapsed is %d", iter2Time);
	
	int iter3Time = benchmark_naive (2000, 10000, 9000, 1000000);
	printf("Total Time elapsed is %d", iter3Time);
	
    return 0;
}





