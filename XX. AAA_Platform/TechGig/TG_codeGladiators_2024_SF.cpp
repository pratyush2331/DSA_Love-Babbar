// Question-1
/*
#include <iostream>
using namespace std;

double getTime(int d, int sp, int rp) {
    double time = ((double)d/(double)sp) + (double)rp;
    return time;
}

int main(int argc, char *a[]) {
    int t;
    cin >> t;

    while(t--) {
        int p, x, r1;
        cin >> p >> x >> r1;

        int n, y, r2;
        cin >> n >> y >> r2;

        double paulTime = getTime(p, x, r1);
        double ninaTime = getTime(n, y, r2);
        // cout << paulTime << endl;
        // cout << ninaTime << endl;

        if(paulTime == ninaTime) {
            cout << "BOTH\n" << (int)paulTime << "\n";
        }
        else if(paulTime < ninaTime) {
            cout << "PAUL\n" << (int)paulTime << "\n";
        }
        else {
            cout << "NINA\n" << (int)ninaTime << "\n";
        }
    }

    return 0;
}
*/





// Question-2
/*
Optimizing Competition (100 Marks)
A thrilling boat competition is on the horizon, and N enthusiastic participants are eager to team up and participate. Each participant has a weight, represented by Wi. However, there is a catch - the competition only allows teams consisting of two participants. As an organizer, you want to ensure fairness by allowing only teams with the same total weight.

For instance, if there are K teams, each comprising participants (a1, b1), (a2, b2), ..., (ak, bk), where ai is the weight of the first participant in the i-th team, and bi is the weight of the second participant in the i-th team, a key condition needs to be satisfied: a1 + b1 = a2 + b2 = ... = ak + bk = s, where s is the common total weight of each team.

Your challenge is to find an optimal value for s such that the maximum possible number of teams can be formed. It is important to note that each participant can only be part of one team.


Input Format
The first line contains an integer N, the number of participants.

The second line contains N space-separated integers W1, W2, ..., WN, where wi represents the weight of the i-th participant.


Constraints
1 ≤ N ≤ 50
1 ≤ Wi ≤ N


Output Format
Print the maximum number of teams that can be formed with the optimal total weight s.

Sample TestCase 1
Input
6
1 1 3 4 2 2
Output
2

Explanation

There are two possible cases:

Case 1: The value of s = 3

Two teams can be formed (1, 2) and (1, 2).

Case 2: The value of s = 4

Two teams can be formed (1, 3) and (2, 2).


In any case, the maximum number of valid teams formed are 2.
*/

#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }

    int maxi=0;
    for(int i=2;i<=(2*n);i++){ // s ranges from [2, 2*n]
        int total=0;
        for(auto j : mp){
            int other=i-j.first;
            if(other>=1 && mp.count(other))
                total+=min(j.second,mp[other]);
        }
        total/=2;
        maxi=max(maxi,total);
    }
    cout<<maxi<<"\n";

    return 0;
}