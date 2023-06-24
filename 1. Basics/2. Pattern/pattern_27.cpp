/*
                                        1234554321
            n=5    --->                 1234**4321
                                        123****321
                                        12******21
                                        1********1
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            cout<<j;
            j++;
        }
        int k=0;
        while(k < (2*i)-2){
            cout<<"*";
            k++;
        }
        int l=n-i+1;
        while(l>=1){
            cout<<l;
            l--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}