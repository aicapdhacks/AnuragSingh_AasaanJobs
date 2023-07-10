// 1) Help Sheeba out 									    10 marks

// Sheeba was asked by a Recruiter to write down 100 numbers (1-100) randomly 
// but making sure that no number is repeated twice. At the end, the Recruiter found 
// out that Sheeba had done her work perfectly, but committed just one mistake of 
// repeating a number twice. Recruiter asked Sheeba that she recruiter her only 
// under one condition! If Sheeba is able to find out the only number which she is 
// repeated in an optimised manner.

// Can you write a pseudocode, which can help Sheeba to find out the number which 
// got repeated twice?

// in c++
#include <iostream>
#include <stdlib.h>

#define asize 100
using namespace std;

 
int printRepeating(int arr[], int size)
{  
  int count[size];
  for(int i=0;i<size;i++) 
  {
         count[i]=0;
  } 
  for (int i = 0; i < size; i++)
  {
    count[arr[i]-1]++;
  }
  for(int i=0;i<size;i++) 
  {
         if(count[i]==2)
         {
               return i+1; 
         }              
  } 
  return 0;
}
 
int main()
{
  int arr[asize] ;
  // enter the 100 numbers
  for(int i=0;i<asize;i++)
  {
      cin>>arr[i];
  }
  cout<<printRepeating(arr, asize);
  getchar();
  return 0;
}



// 3) Closest to zero 									    20 Marks

// This problem is also called minimum absolute sum pair. You are given an array of integers, containing both +ve and -ve numbers. You need to find the two elements such that their sum is closest to zero. eg. Array [15, 5, -20, 30, -45] Output should be 15, -20.

// Note: We want the sum to be closest to zero not minimum. The minimum in the above example would be (-20, -45), but that is incorrect.

//in c++

# include <iostream>
# include <cmath>
# include <climits>

using namespace std;

// function for partitioning
int partition(int arr[], int start, int end)
{
    int x = arr[end];
    int i = (start - 1);
    int j;

    for (j = start; j <= end - 1; j++)
    {
	    if(arr[j] <= x)
	    {
	              i++;
	              int temp; // swapping
                  temp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = temp;
	     }
    }

    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
return (i + 1);
}

// function for quick sort
int quickSort(int arr[], int start, int end)
{
    int p;
    if(start < end)
    {
	         p = partition(arr, start, end);
             quickSort(arr, start, p - 1);
	         quickSort(arr, p + 1, end);
    }
 return 0;
}


int  min_Sum_Pair(int arr[], int N)
{

int sum;
int min_sum = INT_MAX;

int left = 0, right = N-1;

int min_left = left, min_right = N-1;

quickSort(arr, left, right); // srting using quick sort

while(left < right)
{
	sum = arr[left] + arr[right];

	/*If abs(sum) is less then update the result items*/
	if(abs(sum) < abs(min_sum))
	{
	            min_sum = sum;
	            min_left = left;
	            min_right = right;
	}
	if(sum < 0){
	       left++;
        }       
	else{
	       right--;
        }
}

 cout<<" The two elements with minimum sum closest to zero are "<<arr[min_left]<<" and "<<arr[min_right];
		
}


int main()
{
int arr[] = {15, 5, -20, 30, -45};
int n = sizeof(arr)/sizeof(arr[0]);
if(n < 2)
{
	cout<<"number of elements should be more than or equal to two";

	return 0;
}
min_Sum_Pair(arr, n);

return 0;
}



