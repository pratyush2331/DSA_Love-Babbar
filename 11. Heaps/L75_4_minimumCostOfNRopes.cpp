// Minimum Cost of ropes
// GFG : https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

#include<iostream>
using namespace std;

// TC : O(n log n), SC : O(n)
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap
        // insert all elts in min heap
        for(long long i = 0; i < n; i++) { // TC : O(n), SC : O(n)
            pq.push(arr[i]);
        }
        
        long long cost = 0;
        while(pq.size() > 1) { // TC : O(n logn), SC : O(1)
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            cost += sum;
            
            pq.push(sum);
        }
        
        return cost;
    }
};

int main() {
    
    return 0;
}