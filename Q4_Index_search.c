#include<stdio.h>
 
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

int main()
{
    int arr[] = {2,3,3,4,5,5,7,8,10}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
    int value = 3;
    int index = search(value, n, arr);
    if (index != -1)
       printf("Element %d is present at index %d", value, index);
    else
        printf("Element %d is not present", value);
    return 0;
}
