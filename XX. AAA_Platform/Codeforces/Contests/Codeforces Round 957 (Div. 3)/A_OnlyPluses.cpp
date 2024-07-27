// A. Only Pluses
// Codeforces : https://codeforces.com/contest/1992/problem/A

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int a, b, c;
    cin >> a >> b >> c;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);

    for(int i = 0; i < 5; i++) {
        int top = pq.top();
        pq.pop();

        top++;
        pq.push(top);
    }

    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();
    c = pq.top();
    pq.pop();

    cout << a * b * c << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}