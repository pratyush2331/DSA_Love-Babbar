/* Segment Tree Lazy Propogation Code (Not Generic Code) */

/*
segment tree idx starts from 1
t --> segment tree
unpropUpd --> the actual val of un-propogated updates to be processed
isLazy --> tells if a certain node is storing un-propogated updates or not
tl --> starting idx of t
tr --> ending idx of t
l --> query left idx
r --> query right idx
*/

/* Segment Tree Lazy Propogation Code (Not Generic Code) */
class SegTree{
public:
	int len;
	// t is the segment Tree
	vector<int> t, unpropUpd; // the actual val of un-propogated updates to be processed
	vector<bool> isLazy; // tells if a certain node is storing un-propogated updates or not
	
	SegTree(){}
	SegTree(int l){
		len = l;
		t.resize(4 * len);
		isLazy.resize(4 * len);
		unpropUpd.resize(4 * len);
	}
	
	// asking v, to remember that he has 'val' update for his range
	void apply(int v, int tl, int tr, int val){ // [tl, tr] is node range
		if(tl != tr){ // leaf nodes can't be lazy, as they have no-one to propogate to
			isLazy[v] = true;
			unpropUpd[v] = val; //stacking up the unpropogaed value, which i'll propogate down
		}
		t[v] = (tr - tl + 1) * val; // this "= shows assign update", "+= shows range add update" 
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
	
	// Build Segment Tree -- build(a, 1, 0, len-1); 
	void build(vector<int>& a, int v, int tl, int tr){
		if(tl == tr){
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr)/2;
		build(a, 2*v, tl, tm);
		build(a, 2*v+1, tm+1, tr);
		t[v] = t[2*v] + t[2*v+1];
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
	void build(vector<int>& a){
		build(a, 1, 0, len-1);
	}
	
	int query(int l, int r){
		return query(1, 0, len-1, l, r);
	}
	
	void update(int l, int r, int val){
		update(1, 0, len-1, l, r, val);
	}
};

int main()
{
	// Shortcut to run the program is Ctrl + Shift + B
	// Shortcut to run using separate test is Ctrl + Alt + B

	int n = 8;
	vector<int> a = {1, 2, 1, 4, 2, 3, 1, 1};
	
	SegTree segTree(n);
	segTree.build(a);
	
	// Build - View Build Data
	for(int i=0; i<n; i++){
		cout<< segTree.query(i, i) <<" ";
	}cout<<endl;
	
	
	// Query - Range Query
	int sum = segTree.query(1, 5);
	cout<< "Sum for range id = 1 to id = 5 is: "<<sum<<endl;
	
	// Update - Point Update
	segTree.update(2, 2, 10); //at id=2 [i.e. l=2, r=2],make the value = 10
	sum = segTree.query(1, 5);
	cout<< "New Sum for range id = 1 to id = 5 is: "<<sum<<endl;
	
	for(int i=0; i<n; i++){
		cout<< segTree.query(i, i) <<" ";
	}cout<<endl<<endl;
	
	segTree.update(2, 7, 10);
	segTree.update(2, 7, 20);
	for(int i=0; i<n; i++){
		cout<< segTree.query(i, i) <<" ";
	}cout<<endl;
	
	sum = segTree.query(2, 3);
	cout<< "New Sum for range l = 2 to r = 3 is: "<<sum<<endl;
}