// Representation of Decimal number in Binary Number System (32 - bit)

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    bool arr[32] = {0};

    int i=0;
    while(i<32 && n > 0){
        arr[i] = n&1;
        i++;
        n = n>>1;
    }
    cout<<endl;
    for(i=31; i>=0; i--){
        cout<<arr[i];
    }
    return 0;
}