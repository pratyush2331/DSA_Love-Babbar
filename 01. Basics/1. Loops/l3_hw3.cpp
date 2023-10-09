// PRIME or NOT

#include<iostream>
using namespace std;

int main(){
    int i=2, n=0;
    bool flag = 0;
    cout<<"Enter any No.: ";
    cin>>n;
    while(i<n){
        if(n % i == 0){
            flag = 1;
            break;
        }
        i++;
    }
    if(flag == 0)
        cout<<"PRIME\n";
    else 
        cout<<"NOT PRIME!\n";
    return 0;
}