// Coding Ninjas - 1 : Number Star Pattern 1
/*
sample i/p:
4

sample o/p:
432*
43*1
4*21
*321
*/

#include<iostream>
using namespace std;

int main()  
{  
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = n; j >= 1;j--) {
            if(j != i)
                cout << j;
            else
                cout << "*";
        }   
        cout << endl;
    } 
    return 0;  
}