// PRATA - Roti Prata
// SPOJ : https://www.spoj.com/problems/PRATA/

// Time Complexity: O(n^2 logn)

/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.
*/

/*
sample i/p:
3
10 4
1 2 3 4
8 1
1
8 8
1 1 1 1 1 1 1 1

sample o/p:
12
36
1
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool isPossible(vector<int> &rank, int n, int m, int mid) {
    int prata = 0;
    for(int i = 0; i < n; i++) {
    	int time = 0;
    	int j = 1;
    	while(time + j*rank[i] <= mid) {
    		time += j*rank[i];
            prata++;
    		j++;
    	}
        if(prata >= m) return true;
    }
    return false;
}

int minCookTime(vector<int> &rank, int n, int m) {
    sort(rank.begin(), rank.end());
    
    int s = 0;
    int e = (m*(m+1)/2) * rank[n-1];
    
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(isPossible(rank, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        vector<int> rank;
        int n, m;
        cin>>m>>n;

        for(int i = 0; i < n; i++) {
            int data;
            cin>>data;
            rank.push_back(data);
        }

        cout<<minCookTime(rank, n, m)<<endl;
    }
    return 0;
}