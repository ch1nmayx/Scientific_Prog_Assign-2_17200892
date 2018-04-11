#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>

void bubbleSort(int s, int arr[]); // function prototype

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


int main() {
	
	int size;
	int i =0, j=0;
	int max;
	int *a;
	printf("Enter the size of the array:");
	scanf("%d",&size);
	printf("Enter the max val:");
	scanf("%d",&max);
	a = randomarray(size,max);
	
	
	printf("Actual array:\n");
	while (i < size) {
		printf("%d ",a[i]);
		i++;
	}
	
	printf("\n\n");
	printf("\n\n");
	
	printf("Array after bubbleSort :\n");
	
	bubblesort(a, size);
	
	while (j < size) {
		printf("%d ",a[j]);
		j++;
	}
	
	return 0;
}



