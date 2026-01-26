#include<bits/stdc++.h>
using namespace std;

int books(vector<int>& A, int B) {
    int n = A.size();
    if(n < B) return -1;

    int sum = 0, maxi = INT_MIN;
    for(int& ele : A) {
        maxi = max(maxi, ele);
        sum += ele;
    }

    int s = maxi, e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(A, n, B, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    vector<int> A;
    int n, B;
    cin>>n>>B;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        A.push_back(data);
    }

    cout<<books(A, B)<<endl;
    
    return 0;
}