// 126. Word Ladder II
// LeetCode : https://leetcode.com/problems/word-ladder-ii/
// GFG : https://www.geeksforgeeks.org/problems/word-ladder-ii/0

#include<bits/stdc++.h>
using namespace std;


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