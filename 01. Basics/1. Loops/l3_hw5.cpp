// PATTERN QUESTION- 2
/*
                                1111
     n=4       -------->        2222
                                3333
                                4444
*/

#include<iostream>
using namespace std;


int main(){
int n, i=1;

    cin>>n;
    
    while(i<=n){
        int j=1;
        while(j<=n){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}