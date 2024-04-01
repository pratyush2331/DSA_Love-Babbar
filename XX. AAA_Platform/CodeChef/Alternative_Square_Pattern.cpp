// Problem Code: SQALPAT
/*
INPUT:
5

OUTPUT:
1 2 3 4 5 
10 9 8 7 6 
11 12 13 14 15 
20 19 18 17 16 
21 22 23 24 25 
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int count=0, odd=0, even=0;
    while(count < n)
    {
        if(count%2 == 0) // for odd: 1,3,5...
        {
            for(int i=1 + (10*odd); i<=5 + (10*odd); i++)
            {
                cout<<i<<" ";
            }
            odd++;
        }
        
        else // for even: 2,4,6...
        {
            for(int i=10 + (10*even); i>=6 + (10*even); i--)
            {
                cout<<i<<" ";
            }
            even++;
        }
        cout<<endl;
        count++;
    }
    return 0;
}