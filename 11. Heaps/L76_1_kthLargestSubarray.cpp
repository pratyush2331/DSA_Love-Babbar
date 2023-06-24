// K-th Largest Sum Contiguous Subarray
// GFG : https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

#include<iostream>
using namespace std;

// Optimal Solution - TC : O(n^2.logk), SC : O(k)
// Approach : using min heap
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        priority_queue<int, vector<int>, greater<int>> pq; // SC : O(k)
        
        for(int i = 0; i < N; i++) { // TC : O(n^2.logk)
            int sum = 0;
            for(int j = i; j < N; j++) {
                sum += Arr[j];
                
                if(pq.size() < K) {
                    pq.push(sum);
                }
                else {
                    if(sum > pq.top()) {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        
        return pq.top();
    }
};





// Brute Force - TC : O(n^2.logn), SC : O(n^2)
/*
class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        vector<int> sumStore; // SC : O((n*(n+1))/2) = O(n^2)
        
        for(int i = 0; i < N; i++) { // TC : O(n^2.logn)
            int sum = 0;
            for(int j = i; j < N; j++) {
                sum += Arr[j];
                sumStore.push_back(sum);
            }
        }
        
        sort(sumStore.begin(), sumStore.end());
        
        int size = sumStore.size();
        return sumStore[size-K];
    }
};
*/

int main() {
    
    return 0;
}