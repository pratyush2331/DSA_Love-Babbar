// 3081. Replace Question Marks in String to Minimize Its Value
// LeetCode : https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n)
SC : O(n)
*/
class Solution {
public:
    string minimizeStringValue(string s) {
        string ans = s; // SC:O(n)
        
        vector<int> mp(26,0); // map --> {idx, cnt}
        int countQMark = 0;
        queue<int> q; // SC:O(n)
        int i = 0;
        for(char ch : ans) { // TC:O(n)
            if(ch == '?') {
                countQMark++;
                q.push(i);
                // cout << q.front() << " ";
            }
            else {
                mp[ch-'a']++;
                
            }
            i++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap --> {cnt, idx}, SC:O(n)
        for(int i = 0; i < 26; i++) { // TC:O(1)
            pq.push({mp[i], i});
        }
        
        vector<char> chmp; // SC:O(1)
        while(countQMark >= 1) { // TC:O(n)
            pair<int,int> top = pq.top();
            pq.pop();
            
            chmp.push_back(top.second + 'a');
            top.first++;
            pq.push(top);
            countQMark--;
        }
        
        sort(chmp.begin(), chmp.end()); // TC:O(1), SC:O(1)
        
        i = 0;
        while(!q.empty()) { // TC:O(n)
            int idx = q.front();
            q.pop();
            ans[idx] = chmp[i++];
        }
        
        return ans;
    }
};


int main() {
    

    return 0;
}