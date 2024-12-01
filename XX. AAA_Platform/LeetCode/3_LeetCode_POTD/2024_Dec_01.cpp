// 1346. Check If N and Its Double Exist
// LeetCOde : https://leetcode.com/problems/check-if-n-and-its-double-exist/

#include<bits/stdc++.h>
using namespace std;


// method-2 : map
/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            if((mp.find(2*arr[i]) != mp.end()) || (arr[i] % 2 == 0 && mp.find(arr[i]/2) != mp.end())) return true;
            mp[arr[i]]++;
        }
        return false;
    }
};



// method-1 : Sorting + Binary Search
/*
TC : O(n.logn)
SC : O(1)
*/
class Solution {
    int binarySearch(vector<int>& arr, int target) {
        int s = 0, e = arr.size()-1;
        while(s <= e) {
            int mid = s + (e-s) / 2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) e = mid-1;
            else s = mid+1;
        }
        return -1;
    }

public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt0 = 0;
        for(int i = 0; i < arr.size(); i++) {
            int idx = binarySearch(arr, 2*arr[i]);
            if(idx != -1 && idx != i) return true;
        }
        return false;
    }
};



// method-0 : Brute Force
/*
TC : O(n^2)
SC : O(1)
*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i+1; j < arr.size(); j++) {
                if((arr[i] == 2 * arr[j]) || (arr[j] == 2 * arr[i])) return true;
            }
        }
        return false;
    }
};


int main() {
    
    return 0;
}