// 85. Maximal Rectangle
// LeetCode : https://leetcode.com/problems/maximal-rectangle/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
    // using code of Largest Area Histogram (STACK)
    /*
    TC : O(n * (m+n))
    SC : O(n)
    */
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1; i >= 0; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i = 0; i < n; i++) {
            int l = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }

        return area;
    }

    public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;
        
        vector<int> histogram(matrix[0].size());

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }

        return maxi;
    }
};


int main() {
    
    return 0;
}