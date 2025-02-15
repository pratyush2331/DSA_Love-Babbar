// 1352. Product of the Last K Numbers
// LeetCOde : https://leetcode.com/problems/product-of-the-last-k-numbers/

#include<bits/stdc++.h>
using namespace std;


// method : using array/vector
class ProductOfNumbers {
    vector<int> v; // SC:O(n)
    int zeros_idx = -1;

    bool isZero(int k) {
        return zeros_idx != -1 && zeros_idx >= v.size() - k;
    }

public:
    ProductOfNumbers() {
        v.push_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            zeros_idx = v.size();
            v.push_back(1);
        }
        else{
            v.push_back(v.back() * num);
        }
    }
    
    int getProduct(int k) {
        return isZero(k) ? 0 : v.back() / v[v.size() - k - 1];
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}