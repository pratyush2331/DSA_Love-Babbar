// First negative integer in every window of size k
// GFG : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include<iostream>
#include<queue>
using namespace std;

// Implementing using QUEUE
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    vector<long long> ans; // for storing first -ve element for every window
    queue<long long int> dq; // for storing index of -ve elements
    
    // process first window of K size
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push(i);
        }
    }
    
    // store answer of first K sized window
    if(dq.size() > 0) {
        ans.push_back(A[dq.front()]);
    }
    else {
        ans.push_back(0);
    }
    
    // process for remaining windows
    for(int i = K; i < N; i++) {
        // removal part
        if(!dq.empty() && i-dq.front() >= K) {
            dq.pop();
        }
        
        // addition
        if(A[i] < 0) {
            dq.push(i);
        }
        
        // ans store
        if(dq.size() > 0) {
            ans.push_back(A[dq.front()]);
        }
        else {
            ans.push_back(0);
        }
    }
    return ans;
 }

int main() {
    
    return 0;
}
