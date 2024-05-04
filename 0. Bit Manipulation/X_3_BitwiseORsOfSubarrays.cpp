// 898. Bitwise ORs of Subarrays
// LeetCode : https://leetcode.com/problems/bitwise-ors-of-subarrays

#include<bits/stdc++.h>
using namespace std;


// method-1 : all possible sub-arrays -> xorSum
/*
TC : O(n^2)
SC : O(n)
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;
        for(auto ele : arr) { // TC:O(n^2)
            unordered_set<int> temp;
            for(auto x : prev) { // TC:O(n)
                temp.insert(x | ele);
            }
            temp.insert(ele);
            for(auto x : temp) { // TC:O(n)
                ans.insert(x);
            }
            prev = temp;
        }
        return ans.size();
    }
};



// method-0 : all possible sub-arrays -> xorSum ==> will give TLE
/*
TC : O(n^3)
SC : O(n)
*/
/*
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i; j < arr.size(); j++) {
                int xorSum = 0;
                for(int k = i; k <= j; k++) {
                    // cout << arr[k] << " ";
                    xorSum |= arr[k];
                    ans.insert(xorSum);
                }
                cout << endl;
            }
        }
        return ans.size();
    }
};
*/


int main() {

    return 0;
}