// 3152. Special Array II
// LeetCode : https://leetcode.com/problems/special-array-ii/

#include<bits/stdc++.h>
using namespace std;


/*
TC : O(n.logn)
SC : O(4n)
*/
class SegmentTree {
    vector<int> tree;
    int size;
 
public:
    SegmentTree(vector<int>& array) {
        size = array.size();
        tree.resize(4 * size);
        buildTree(array, 0, 0, size - 1);
    }
 
private:
    void buildTree(vector<int>& array, int treeIndex, int left, int right) {
        if (left == right) { // leaf node is special (1)
            tree[treeIndex] = 1;
            return;
        }

        int mid = left + (right - left) / 2;
        buildTree(array, 2 * treeIndex + 1, left, mid);
        buildTree(array, 2 * treeIndex + 2, mid + 1, right);
        
        tree[treeIndex] = tree[2 * treeIndex + 1] & tree[2 * treeIndex + 2];
        // intersecting mid & (mid+1)
        if((array[mid]&1) == (array[mid+1]&1)) { // mid & (mid+1) are of same parity
            tree[treeIndex] = 0; // set 0
        }
    }
 
    int query(int treeIndex, int left, int right, int queryLeft, int queryRight, vector<int>& nums) {
        if (queryLeft <= left && queryRight >= right) {
            return tree[treeIndex];
        }
        if(queryLeft > right || queryRight < left) {
            return 1;
        }
        
        int mid = left + (right - left) / 2;

        int leftQuery = query(2 * treeIndex + 1, left, mid, queryLeft, queryRight, nums);
        int rightQuery = query(2 * treeIndex + 2, mid + 1, right, queryLeft, queryRight, nums);
        int ans = leftQuery & rightQuery;
        // intersecting mid & (mid+1)
        if(mid >= queryLeft && mid < queryRight && ((nums[mid] & 1) == (nums[mid + 1] & 1))) { // mid & (mid+1) are of same parity
            ans = 0; // set 0
        }
        return ans;
    }
 
public:
    int query(int left, int right, vector<int>& nums) {
        return query(0, 0, size - 1, left, right, nums);
    }
};

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        SegmentTree st(nums);

        vector<bool> ans;
        for(auto qry : queries) {
            ans.emplace_back(st.query(qry[0], qry[1], nums));
        }
        return ans;
    }
};


int main() {
    
    return 0;
}