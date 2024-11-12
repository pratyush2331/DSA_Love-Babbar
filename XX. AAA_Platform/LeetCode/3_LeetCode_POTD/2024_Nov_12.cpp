// 2070. Most Beautiful Item for Each Query
// LeetCode : https://leetcode.com/problems/most-beautiful-item-for-each-query/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int binarySearch(vector<vector<int>>& items, int targetPrice) {
        int s = 0, e = items.size() - 1;
        int maxBeauty = 0;
        while (s <= e) {
            int mid = s + (e-s)/2;
            if(items[mid][0] > targetPrice) {
                e = mid - 1;
            }
            else {
                // Found viable price. Keep moving to right
                maxBeauty = max(maxBeauty, items[mid][1]);
                s = mid + 1;
            }
        }
        return maxBeauty;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n);

        sort(items.begin(), items.end());
        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for(int i = 0; i < n; i++) {
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }
};


int main() {
    
    return 0;
}