// 126. Word Ladder II
// LeetCode : https://leetcode.com/problems/word-ladder-ii/
// GFG : https://www.geeksforgeeks.org/problems/word-ladder-ii/0

#include<bits/stdc++.h>
using namespace std;


// method-1 : BFS + DFS
// working in LeetCode
// approach : BFS from beginWord till we reach endWord
// then dfs from endWord to beginWord, to find all the pathsh
class Solution {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    string begWord;

    void dfs(string& word, vector<string>& seq) {
        if(word == begWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        for(int i = 0; i < word.length(); i++) {
            char originalCh = word[i];
            int lvl = mp[word];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mp[word] + 1 == lvl) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = originalCh;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        int lvl = 1;

        while(!q.empty()) {
            int x = q.size();
            
            while(x--) {
                string word = q.front();
                q.pop();

                if(word == endWord) {
                    break;
                }

                for(int i = 0; i < beginWord.length(); i++) {
                    char originalCh = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[i] = ch;
                        if(st.find(word) != st.end()) {
                            q.push(word);
                            mp[word] = lvl + 1;
                            st.erase(word);
                        }
                    }
                    word[i] = originalCh;
                }
            }
            lvl++;
        }

        if(mp[endWord]) { // transformation possible
            begWord = beginWord;
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};


// method-0
// WARN : will give MLE/TLE in LeetCode, but works fine in GFG
// approach : BFS from beginWord
// only change is : we need to keep track of the path
// and remove the word from the set, in the next level
// so that we can return all the paths of the shortest length
class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // insert wordList in set, to find word in constant time
        unordered_set<string> st(wordList.begin(), wordList.end());

        // do BFS from beginWord
        queue<vector<string>> q;
        q.push({beginWord});
        int lvl = 1;
        vector<vector<string>> ans;

        while(!q.empty()) {
            if(!ans.empty()) { // if last level is reached, break the loop
                break;
            }
            
            int x = q.size();
            
            while(x--) { // one level at a time
                // get the current path
                vector<string> vec = q.front();
                q.pop();

                string word = vec.back();
                st.erase(word); // remove word from set, to avoid cycles and redundant paths

                if(word == endWord) { // endWord found
                    if(ans.empty() || ans[0].size() == vec.size()) {
                        ans.push_back(vec);
                    }
                }

                for(int i = 0; i < word.length(); i++) { // go through every idx of word
                    int originalCh = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) { // try all possible character for i-th idx
                        word[i] = ch;
                        if(st.find(word) != st.end()) { // word present in set
                            vec.push_back(word);
                            q.push(vec);
                            vec.pop_back();
                        }
                    }
                    word[i] = originalCh;
                }
            }
            lvl++;
        }

        // returning the ans
        return ans;
    }
};


int main() {
    
    return 0;
}