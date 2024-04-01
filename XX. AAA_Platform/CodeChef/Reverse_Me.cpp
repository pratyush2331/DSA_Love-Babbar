// Problem Code:REVMEE
// Reverse the elements of a vector / array
/*
Input:
4
1 3 2 4

Output:
4 2 3 1
*/

#include <iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	
	vector<int> arr;
	
	int ele;
	
	for(int i=0; i<n; i++)
	{
	    cin>>ele;
	    arr.push_back(ele);
	}
	
	// Reversing th array
	int start = 0, end = n-1;
	while(start < end)
	{
	    swap(arr[start], arr[end]);
	    start++;
	    end--;
	}
	for(int i=0; i<n; i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}
