// Sum of minimum and maximum elements of all subarrays of size k.
// GFG : https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

#include<iostream>
#include<queue>
using namespace std;

// TC : O(N), SC : O(K)
int solve(int* arr, int n, int k) {
    deque<int> maxi(k);
    deque<int> mini(k);

    // addition of first k size window
    for(int i = 0; i < k; i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        
        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    // remaining windows ko process karlo
    for(int i = k; i < n; i++) {
        // removal
        while(!maxi.empty() && i-maxi.front() >= k) {
            maxi.pop_front();
        }
        
        while(!mini.empty() && i-mini.front() >= k) {
            mini.pop_front();
        }
        
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]) {
            maxi.pop_back();
        }
        
        while(!mini.empty() && arr[mini.back()] >= arr[i]) {
            mini.pop_back();
        }

        // addition
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }

    return ans;
}

int main() {
    int n = 7;
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int k = 4;

    cout << solve(arr, n, k) << endl;
    
    return 0;
}