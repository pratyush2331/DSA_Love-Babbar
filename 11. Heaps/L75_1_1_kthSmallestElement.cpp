// Kth smallest element
// GFG : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

// TC : O(n logk), SC : O(k)

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    // using max heap
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        
        // max heap (default)
        priority_queue<int> pq;
        
        // step-1: insert in max heap of size k
        // TC : n*O(logk) = O(n logk), SC : O(k)
        for(int i = l; i < k; i++) { // TC : O(n)
            pq.push(arr[i]); // TC : O(logk)
        }
        
        // step-2: k to (n-1) elts ko comapre kro aur max heap me daalo
        // TC : O(n logk)
        for(int i = k; i <= r; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // step-3: return pq.top()
        return pq.top();
    }
        
        // step-3: return pq.top()
        return pq.top();
    }
};

int main() {
    
    return 0;
}