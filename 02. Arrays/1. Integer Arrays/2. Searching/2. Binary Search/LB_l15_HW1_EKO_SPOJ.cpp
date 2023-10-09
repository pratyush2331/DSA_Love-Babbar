// EKO
// SPOJ : https://www.spoj.com/problems/EKO/

/*
sample i/p 1:
4 7
20 15 10 17
sample o/p 1:
15

sample i/p 2:
5 20
4 42 40 26 46
sample o/p 2:
36
*/

#include <iostream>
#include <vector>
#define int long long int

using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid) {
    int sub = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > mid) {
            sub += (arr[i] - mid);
        }
        if(sub >= m) return true;
    }
    return false;
}

int allocateWoods(vector<int> arr, int n, int m) {
    int s = 0;
    
    int maxi = -1;
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);;
    }
    
    int e = maxi;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(arr, n, m, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int32_t main() {
    vector<int> arr;
    int n, m;
    cin>>n>>m;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        arr.push_back(data);
    }

    cout<<allocateWoods(arr, n, m)<<endl;

    return 0;
}