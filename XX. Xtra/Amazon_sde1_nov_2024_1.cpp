// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
ll getMaxEfficiency(vector<int> parcel_weights) {
    int n = parcel_weights.size();
    int s, e;
    int mid = n / 2;
    ll ans = 0LL;
    
    if (n & 1) { // Odd
        ans += parcel_weights[mid];
        s = mid - 1;
        e = mid + 1;
    }
    else {
        s = mid - 1;
        e = mid;
    }
    
    priority_queue<int> pq; // max-heap
    while (s >= 0 && e < n) {
        pq.push(parcel_weights[s]);
        pq.push(parcel_weights[e]);
        
        ans += pq.top();
        pq.pop();

        s--;
        e++;
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<int> parcel_weights(n);
    for(int i = 0; i < n; i++) {
        cin >> parcel_weights[i];
    }

    cout << getMaxEfficiency(parcel_weights) << "\n";
    
    return 0;
}