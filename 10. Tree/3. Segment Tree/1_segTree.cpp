/*
Segment Tree : 
1. Build Segment Tree
2. Point Query & Point Update
3. Range Query & Range Update --> Lazy Propagation
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int seg[4 * MAXN];
int lazy[4 * MAXN];

// TC : O(n)
void build(vector<int>& arr, int idx, int low, int high) {
    if(low == high) {
        seg[idx] = arr[low];
        return;
    }
    int mid = low + (high - low)/2;
    build(arr, 2*idx+1, low, mid);
    build(arr, 2*idx+2, mid+1, high);
    seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
}

// point-max-query
// TC : O(logn)
int pointQuery(int idx, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg[idx];
    if(high < l || low > r) return INT_MIN;
    int mid = low + (high - low)/2;
    int left = pointQuery(2*idx+1, low, mid, l, r);
    int right = pointQuery(2*idx+2, mid+1, high, l, r);
    return max(left, right);
}

// point-max-update
// TC : O(logn)
void pointUpdate(int idx, int low, int high, int node, int val) {
    if(low == high) {
        seg[idx] += val;
    }
    else {
        int mid = low + (high - low)/2;
        if(node <= mid && node >= low) pointUpdate(2*idx+1, low, mid, node, val);
        else pointUpdate(2*idx+2, mid+1, high, node, val);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }
}

// range-sum-update : lazy-propagation
/**
 * Increment elements within range [l, r] with value val
 */
// TC : O(logn)
void rangeUpdate(int idx, int low, int high, int l, int r, int val) {
  	if(lazy[idx] != 0) { // This idx needs to be updated
   		seg[idx] += (high-low+1)*lazy[idx]; // Update it
		if(low != high) {
			lazy[2*idx+1] += lazy[idx]; // Mark child as lazy
            lazy[2*idx+2] += lazy[idx]; // Mark child as lazy
		}
   		lazy[idx] = 0; // Reset it
  	}
  
	if(low > high || low > r || high < l) { // case 1 : Current segment is not within range [l, r]
		return;
    }
    
  	if(low >= l && high <= r) { // case 2 : Segment is fully within range
        seg[idx] += (high-low+1)*val;
		if(low != high) { // Not leaf node
			lazy[2*idx+1] += val;
			lazy[2*idx+2] += val;
		}
        return;
	}

    // case 3
    int mid = low + (high - low)/2;
	rangeUpdate(2*idx+1, low, mid, l, r, val); // Updating left child
	rangeUpdate(2*idx+2, mid+1, high, l, r, val); // Updating right child
	seg[idx] = max(seg[2*idx+1], seg[2*idx+2]); // Updating root with max value
}

// range-sum-query : lazy-propagation
/**
 * Query tree to get sum of element value within range [l, r]
 */
// TC : O(logn)
int rangeQuery(int idx, int low, int high, int l, int r) {
    if(lazy[idx] != 0) { // This idx needs to be updated
		seg[idx] += (high-low+1)*lazy[idx]; // Update it
		if(low != high) {
			lazy[2*idx+1] += lazy[idx]; // Mark child as lazy
			lazy[2*idx+2] += lazy[idx]; // Mark child as lazy
		}
		lazy[idx] = 0; // Reset it
	}
	
    // case 1
	if(low > high || low > r || high < l) { // Out of range
        return 0;
    }

    // case 2
	if(low >= l && high <= r) { // Current segment is totally within range [l, r]
		return seg[idx];
    }

    // case 3
    int mid = low + (high - low)/2;
	int left = rangeQuery(2*idx+1, low, mid, l, r); // Query left child
	int right = rangeQuery(2*idx+2, mid+1, high, l, r); // Query right child
	return left + right; // Return final result
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(arr, 0, 0, n-1);

    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << pointQuery(0, 0, n-1, l, r) << "\n";
    }
    
    return 0;
}