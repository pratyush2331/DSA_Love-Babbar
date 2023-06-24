// Sum of ALL EVEN Numbers upto n

#include<iostream>
using namespace std;

int main(){
    int n, i=2, sum=0;
    cin>>n;
    while(i<=n){
        sum += i;
        i += 2;
    }
    cout<<"Sum of all EVEN numbers upto "<<n<<" = "<<sum;
    return 0;
}