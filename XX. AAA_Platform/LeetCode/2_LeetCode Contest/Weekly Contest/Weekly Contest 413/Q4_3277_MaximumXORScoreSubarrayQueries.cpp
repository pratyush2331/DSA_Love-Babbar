// 3277. Maximum XOR Score Subarray Queries
// LeetCode : https://leetcode.com/problems/maximum-xor-score-subarray-queries/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using DP (bottom-up)
/*
TC : O(n^2)
SC : O(n^2)
*/
class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        
        for(int st = n-1; st >= 0; st--) {
            for(int end = st+1; end < n; end++) {
                dp[st][end] = dp[st][end-1] ^ dp[st+1][end];
            }
        }

        for(int st = n-1; st >= 0; st--) {
            for(int end = st+1; end < n; end++) {
                dp[st][end] = max(dp[st][end], max(dp[st][end-1], dp[st+1][end]));
            }
        }

        vector<int> ans;
        for(vector<int>& quer: queries) {
            int st = quer[0], end = quer[1];
            ans.push_back(dp[st][end]);
        }

        return ans;
    }
};


// method-0 : using Segment Trees
/*
TC : O(n^2.logn + q.logn)
SC : O(n^2)
*/
#define ll long long
class SegTree {
    public:
        vector<ll> v;
        vector<ll> tree;
        int n;

        SegTree() {}

        SegTree(vector<ll> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        ll mergee(ll l, ll r) {
            return max(l, r);
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = v[ie];
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        ll get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return -1;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	ll l = get(qs, qe, left, is, mid);
        	ll r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i] = val;
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	update(index, val, left, is, mid);
        	update(index, val, right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }
};

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int> &v, vector<vector<int>> &q) {
        int n = v.size();

        vector<vector<ll>> a(n);

        for (int i=0 ; i<n ; i++) {
            a[i].resize(i+1);
            a[i][i] = v[i];
        }

        int sz = 1;
        while(!v.empty()) {
            for (int i=0 ; i<v.size()-1 ; i++) {
                int j = i+sz;
                v[i] ^= v[i+1];
                a[j][i] = max(v[i]*1ll, a[j-1][i]);
            }
            sz++;
            v.pop_back();
        }

        vector<SegTree> seg;

        for (int i=0 ; i<n ; i++) {
            seg.push_back(SegTree(a[i]));
        }

        vector<int> ans;
        for (vector<int> &qq:q) {
            int x = qq[0];
            int y = qq[1];

            ans.push_back(seg[y].get(x, y, 0, 0, seg[y].n-1));
        }

        return ans;
    }
};


int main() {
    
    return 0;
}