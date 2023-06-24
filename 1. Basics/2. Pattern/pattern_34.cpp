// Coding Ninjas - 2 : Zeros and Stars Pattern
/*
sample i/p:
4

sample o/p:
4
*000*000*
0*00*00*0
00*0*0*00
000***000
*/

#include<iostream>
using namespace std;

int main()  
{  
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        // For left part
        for(int j = 1; j <= n; j++) {
            if(j != i)  
                cout << "0";
            else
                cout << "*";
        } 

        cout << "*";

        // For right part
        for(int j = n; j >= 1; j--) {
            if(j != i)
                cout << "0";
            else
                cout << "*";
        }   

        cout << endl;
    }   

    return 0;  
}