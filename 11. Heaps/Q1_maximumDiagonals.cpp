// Maximum Diamonds
// GFG : https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1

/*
TC : O(n.logn)
SC : O(n)
*/

#include<iostream>
using namespace std;

class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
        priority_queue<int> pq;
        for(int i = 0; i < N; i++) {
            pq.push(A[i]);
        }
        
        long long ans = 0;
        while(K--) { // jab tak time 0 nhi ho jata
            int val = pq.top();
            pq.pop();
            
            ans += val;
            pq.push(val/2);
        }
        
        return ans;
    }
};

int main() {
    
    return 0;
}