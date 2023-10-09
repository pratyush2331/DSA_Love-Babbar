// sqrt(x) with precision using Binary Search

#include<bits/stdc++.h>
using namespace std;

long long int sqrtInteger(int x);
double morePrecision(int x, int precision, int tempSol);

int main(){
    int x;
    cout<<"Enter the number: "<<endl;
    cin>>x;

    int tempSol = sqrtInteger(x);
    cout<<"Answer is "<<morePrecision(x, 3, tempSol);
    return 0;
}

long long int sqrtInteger(int x) {
    int s = 0, e = x;
    long long int mid = s + (e-s)/2;
    long long int ans;
    while(s <= e) {
        long long int square = mid*mid;
        if(square == x) return mid;
        if(square < x) {
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
        mid = s + (e-s)/2;
    }
    return ans;
}

double morePrecision(int x, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision; i++) {
        factor = factor/10;
        for(double j = ans; j*j <= x; j += factor) {
            ans = j;
        }
    }
    return ans;
}