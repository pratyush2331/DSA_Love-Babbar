// 2381. Shifting Letters II
// LeetCode : https://leetcode.com/problems/shifting-letters-ii/

#include<bits/stdc++.h>
using namespace std;


/* Segment Tree Lazy Propogation Code (Not Generic Code) */
class SegTree{
public:
	int len;
	// t is the segment Tree
	vector<long long> t, unpropUpd; // the actual val of un-propogated updates to be processed
	vector<bool> isLazy; // tells if a certain node is storing un-propogated updates or not
	
	SegTree(){}
	SegTree(int l){
		len = l;
		t.resize(4 * len);
		isLazy.resize(4 * len, false);
		unpropUpd.resize(4 * len, 0);
	}
	
	// asking v, to remember that he has 'val' update for his range
	void apply(int v, int tl, int tr, int val){ // [tl, tr] is node range
		if(tl != tr){ // leaf nodes can't be lazy, as they have no-one to propogate to
			isLazy[v] = true;
			unpropUpd[v] += val; //stacking up the unpropogaed value, which i'll propogate down
		}
		t[v] += (tr - tl + 1) * val; // this "= shows assign update", "+= shows range add update" 
	}
	
	// assigning the value whatsoever we had on 'v' to its children ('2*v' & '2*v+1')
	void pushDown(int v, int tl, int tr){
		if(!isLazy[v]) return; // if not lazy then no push-down required
		isLazy[v] = false; //no more lazy
		int tm = (tl + tr)/2;
		apply(2*v, tl, tm, unpropUpd[v]); // propogates to left child
		apply(2*v+1, tm+1, tr, unpropUpd[v]); // propogates to right child
		unpropUpd[v] = 0; // identity-transformation -- updated the children(job done)
	}
	
	// Query input question is = [l, r] included -- query(1, 0, len-1, l, r)
	int query(int v, int tl, int tr, int l, int r){
		if(tl > r || tr < l) return 0; // no overlap
		if(l <= tl && tr <= r) return t[v]; //Full overlap
		
		// Partial Overlap
		pushDown(v, tl, tr); //we remove the lazy tag before going down, so children have correct info
		int tm = (tl + tr)/2;
		int leftAns = query(2*v, tl, tm, l, r);
		int rightAns = query(2*v+1, tm+1, tr, l, r);
		return leftAns + rightAns;
	}
	
	// Update at index id of nums to a value val (assign/override/set) -- update(1, 0, len-1, l, r, val) 
	void update(int v, int tl, int tr, int l, int r, int val){
		// reached leaf node
		if(l <= tl && tr <= r){ // full overlap -- apply update and return back
			apply(v, tl, tr, val); 
			return;
		}
		if(tl > r || tr < l) return; // no overlap
		
		// Partial Overlap
		pushDown(v, tl, tr);
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, l, r, val);
		update(2*v+1, tm+1, tr, l, r, val);
		t[v] = t[2*v] + t[2*v+1];
	}
	
	//over-ridden functions
	int query(int l, int r){
		return query(1, 0, len-1, l, r);
	}
	
	void update(int l, int r, int val){
		update(1, 0, len-1, l, r, val);
	}
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        SegTree st(n); // SC:O(12.n)
        
        for(auto& shift : shifts) { // TC:(m.logn)
            int l = shift[0], r = shift[1], val = shift[2] ? 1 : -1;
            st.update(l, r, val); // range update
        }

        string ans = s;
        for(int i = 0; i < n; i++) { // TC:O(n.logn)
            int totalShift = ((s[i] - 'a') + st.query(i, i)) % 26; // point query
            ans[i] = 'a' + ((totalShift < 0) ? totalShift + 26 : totalShift);
        }
        return ans;
    }
};


int main() {
    
    return 0;
}