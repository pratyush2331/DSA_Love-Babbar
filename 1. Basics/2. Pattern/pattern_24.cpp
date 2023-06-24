/*
                                1234
        n=4    --->              234
                                  34
                                   4
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int space = i-1;
        while(space){
            cout<<" ";
            space--;
        }
        int j = n-i+1;
        int count=i;
        while(j>=1){
            cout<<count;
            count++;
            j--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}