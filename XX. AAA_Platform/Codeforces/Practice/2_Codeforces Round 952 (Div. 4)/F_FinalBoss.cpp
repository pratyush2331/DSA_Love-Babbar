// F. Final Boss
// Codeforces : https://codeforces.com/contest/1985/problem/F

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, int>;


// method-1 : using Binary Search
/*
TC : O(n.logn)
SC : O(n)
*/
bool isPossible(ll turn, ll h, vector<ll>& damage, vector<ll>& cooldown) {
    ll totalDamage = 0;
    for(int i = 0; i < damage.size(); i++) {
        totalDamage += (damage[i] * (1 + (turn-1)/cooldown[i]));
        if(totalDamage >= h) return true; // to avoid integer overflow, to rduce totalDamage value
    }
    return false;
}

void run() {
    ll h, n;
    cin >> h >> n;

    vector<ll> damage(n), cooldown(n);
    for(int i = 0; i < n; i++) {
        cin >> damage[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cooldown[i];
    }

    ll lo = 1, hi = 4*1e11;
    ll mid = lo + (hi-lo)/2;
    ll ans = -1;
    while(lo <= hi) {
        if(isPossible(mid, h, damage, cooldown)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
        mid = lo + (hi-lo)/2;
    }

    cout << ans << "\n";
}


// method-0 : using Priority Queue
/*
void run() {
    ll h, n;
    cin >> h >> n;

    vector<ll> damage(n), cooldown(n);
    for(int i = 0; i < n; i++) {
        cin >> damage[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> cooldown[i];
    }

    // Min-heap to manage the cooldowns of attacks
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for(int i = 0; i < n; i++) {
        pq.push({0, i}); // All attacks are initially available at turn 0
    }

    ll turn = 0;
    while(h > 0) {
        turn++;

        ll totalDamage = 0;
        while(pq.top().first <= turn) {
            int idx = pq.top().second;
            pq.pop();

            totalDamage += damage[idx];
            pq.push({turn + cooldown[idx], idx});
        }

        if(totalDamage == 0) {
            // If no attack was available, skip to the next available attack time
            turn = pq.top().first - 1; // The loop will increment turn, so we adjust here
        } else {
            h -= totalDamage;
        }
    }

    cout << turn << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) run();

    return 0;
}