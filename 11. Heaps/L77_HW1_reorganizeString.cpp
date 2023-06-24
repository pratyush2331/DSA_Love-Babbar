// 767. Reorganize String
// LeetCode : https://leetcode.com/problems/reorganize-string/

/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.
*/

#include<iostream>
using namespace std;

// OPTIMAL SOLUTION (using map only)
/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();

        // create map to store characters and their frequencies
        int map[26] = {0}; // SC: O(1)
        for(int i = 0; i < n; i++) { // TC: O(n)
            map[s[i]-'a']++;
        }

        int maxFreq = -1, maxFreqChar = '#';
        // finding 'maxFreqChar' and 'maxFreq'
        for(int i = 0; i < 26; i++) { // TC: O(1)
            if(map[i] > maxFreq) {
                maxFreq = map[i];
                maxFreqChar = i + 'a';
            }
        }

        // Not Possible
        if(maxFreq > (n+1)/2)
            return "";

        int index = 0;
        while(maxFreq > 0 && index < n) { // TC: O(n)
            s[index] = maxFreqChar;
            index += 2;
            maxFreq--;
        }

        map[maxFreqChar - 'a'] = 0;

        for(int i = 0; i < 26; i++) {
            while(map[i] > 0) { // TC: O(n)
                index = (index >= n) ? 1 : index;
                s[index] = i + 'a';
                index += 2;
                map[i]--;
            }
        }

        return s;
    }
};



// BRUTE FORCE (using Heap)
/*
TC : O(n.logn) // heap -> push(),pop() for n elements
SC : O(n) // heap
*/
/*
class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";

        // create map to store characters and their frequencies
        unordered_map<char,int> map; // SC: O(1)
        
        int n = s.length();
        for(int i = 0; i < n; i++) { // TC: O(n)
            map[s[i]]++;
        }

        priority_queue<pair<int,char>> pq; // max heap of pair type - {freq, char}

        // put characters having (freq > 0) in max heap
        for(int i = 'a'; i <= 'z'; i++) { // TC: O(1)
            if(map[i]) {
                pq.push(make_pair(map[i], i));
                cout << pq.top().first << " " << pq.top().second << endl;
            }
        }

        if(pq.top().first > (n+1)/2) // TC: O(logn)
            return ans; // ans is empty
        
        // add characters in 'ans' string having highest freq which is not selected just before
        pair<int,char> prev = {-1,'#'};
        while(!pq.empty()) { // TC: O(n.logn)
            pair<int,char> curr = pq.top();
            pq.pop();
            ans = ans + curr.second;
            if(prev.first > 0) {
                pq.push(prev);
            }
            curr.first--;
            prev = curr;
        }

        return ans;
    }
};
*/

int main() {
    
    return 0;
}