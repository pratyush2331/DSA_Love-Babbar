// EKO
// SPOJ : https://www.spoj.com/problems/EKO/

/*
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine 
that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade 
to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). 
Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, 
and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, 
and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree 
(7 metres of wood in total).

Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade 
as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least 
M metres of wood.
*/

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