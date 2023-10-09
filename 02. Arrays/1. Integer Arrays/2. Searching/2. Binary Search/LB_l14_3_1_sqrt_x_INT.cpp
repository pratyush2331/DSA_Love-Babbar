// 69. Sqrt(x)
// LeetCode : https://leetcode.com/problems/sqrtx/

// sqrt(x) in nearest lowest integer using Binary Search

#include<bits/stdc++.h>
using namespace std;

long long int mySqrt(int x);

int main(){
    int x;
    cin>>x;

    cout<<mySqrt(x);
    return 0;
}

int mySqrt(int x) {
    int s = 0, e = x;
    long long int mid = s + (e-s)/2;
    int ans;
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
