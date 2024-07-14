// 3219. Minimum Cost for Cutting Cake II
// LeetCode : https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii

#include<bits/stdc++.h>
using namespace std;


#define ll long long
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        ll totalCost = 0;

        int rows = 1, i = 0;
        int cols = 1, j = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] > verticalCut[j]) {
                totalCost += (1LL * horizontalCut[i] * cols);
                rows++;
                i++;
            } else {
                totalCost += (1LL * verticalCut[j] * rows);
                cols++;
                j++;
            }
        }
        
        while (i < m - 1) {
            totalCost += (1LL* horizontalCut[i] * cols);
            rows++;
            i++;
        }

        while (j < n - 1) {
            totalCost += (1LL * verticalCut[j] * rows);
            cols++;
            j++;
        }

        return totalCost;
    }
};


int main() {
    
    return 0;
}