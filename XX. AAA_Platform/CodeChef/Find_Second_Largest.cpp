// Problem Code: SECLAR
// Find 2nd largest element out of three elements

/*
Input:
2
7
21

Output:
7
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int arr[3];
	for(int i=0; i<3; i++)
	{
	    cin>>arr[i];
	}
	
	// Selection sort
	for(int i=0; i<2; i++)
	{
	    for(int j=i+1; j<3; j++)
	    {
	        if(arr[i] > arr[j])
	        {
	            swap(arr[i], arr[j]);
	        }
	    }
	}
	
	// find 2nd maximum element in array
	int ans=arr[2];
	for(int i=1; i>=0; i--)
	{
	    if(arr[i] != arr[2])
	    {
	        ans = arr[i];
	        break;
	    }
	}
	cout<<ans;
	return 0;
}
