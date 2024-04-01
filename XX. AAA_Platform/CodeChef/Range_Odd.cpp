// Problem Code:RNGEODD
// Print all odd numbers b/w given range a,b inclusive
/*
Input:
2 9

Output:
3 5 7 9
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int L, R;
	cin>>L>>R;
	for(int i=L; i<=R; i++)
	{
	    if(i%2 != 0)
	    {
	        cout<<i<<" ";
	    }
	}
	return 0;
}