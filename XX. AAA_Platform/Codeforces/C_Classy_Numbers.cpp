// C. Classy Numbers
// Codeforces : https://codeforces.com/problemset/problem/1036/C
// Submission : https://codeforces.com/contest/1036/submission/233355392

// Tutorial : https://www.youtube.com/watch?v=pSW4mt0JMOM

// Q. You are given a segment [L,R]. Count the number of classy integers x such that L≤x≤R.
// Let's call some positive integer classy if its decimal representation contains no more than 3 non-zero digits.
// For example, numbers 4, 200000, 10203 are classy and numbers 4231, 102306, 7277420000 are not.
// Constraint : 1 ≤ T ≤ 10^4;           1 ≤ Li ≤ Ri ≤ 10^18;

#include<bits/stdc++.h>
#define int long long

using namespace std;

// states.. 
// --> define your current recursive call...
// idx, non_zero, smaller
int dp[20][10][2];
int rec(const string& lim, int idx,int non_zero,bool smaller){
 
    // Lim ==> 1521
    // current:10xx 
    // 
    // non_zero digs <=3
    if(non_zero>3)  return 0;
    int sz=lim.size();
    if(idx==sz) return 1;
    // use a 0 ...
    if(dp[idx][non_zero][smaller]!=-1)  return dp[idx][non_zero][smaller];
    int res=rec(lim,idx+1,non_zero,smaller?smaller:(lim[idx]!='0'));
    if(smaller){        // use digs from 1 to 9
        res+=9*rec(lim,idx+1,non_zero+1,1);
    }
    else{
        // the number is actually exactly sim
        // 27456
        // i=2
        // 27 ... [1,4]
        // 1,2,3 -> smaller 
        int lesser=lim[idx]-'0'-1;      // [1,2]
        if(lesser>0)    res+=lesser*rec(lim,idx+1,non_zero+1,1);
        if(lim[idx]!='0')   res+=rec(lim,idx+1,non_zero+1,0);
    }
    return dp[idx][non_zero][smaller]=res;
}
void solve(){
    int l=0,r=0;
    cin>>l>>r;
    memset(dp,-1,sizeof dp);        // r as well as for l 
    int lResult=rec(to_string(l-1),0,0,0);
 
    memset(dp,-1,sizeof dp); 
    int rResult=rec(to_string(r),0,0,0);
    cout<<rResult-lResult<<"\n";
    
}
 
int32_t main()
{
 
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}