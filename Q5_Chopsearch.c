#include <stdio.h>
 
 
 
// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int chopsearch(int x, int n, int arr[], int l, int r )
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return chopsearch(x,n,arr, l, mid-1);
 
        // Else the element can only be present in right subarray
        return chopsearch(x,n, arr, mid+1, r);
   }
 
   // We reach here when element is not present in array
   return -1;
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 5, 10, 15, 25, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 15;
   int result = chopsearch(x, 8, arr, 0, n-1);
   if (result != -1)
       printf("Element %d is present at index %d", x, result);
    else
        printf("Element %d is not present", x);
   return 0;
}