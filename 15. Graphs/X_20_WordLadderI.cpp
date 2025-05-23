// LeetCode : https://leetcode.com/problems/word-ladder/
// GFG : https://www.geeksforgeeks.org/problems/word-ladder/1

/*
* Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the 
shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
* A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence 
of words beginWord -> s1 -> s2 -> ... -> sk such that:
  1. Every adjacent pair of words differs by a single letter.
  2. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
  3. sk == endWord
*/

#include<bits/stdc++.h>
using namespace std;


// approach : BFS from beginWord
/*
TC : O(N * M^2) where N = wordList.size() and M = length of each word
SC : O(N * M)
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // insert wordList in set, to find word in constant time
        unordered_set<string> st(wordList.begin(), wordList.end());

        // do BFS from beginWord
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        int lvl = 1;

        while(!q.empty()) {
            int x = q.size();
            
            while(x--) { // one level at a time
                string word = q.front();
                q.pop();

                if(word == endWord) { // endWord found
                    return lvl;
                }

                for(int i = 0; i < beginWord.length(); i++) { // go through every idx of word
                    char originalCh = word[i];
                    for(char ch = 'a'; ch <= 'z'; ch++) { // try all possible character for i-th idx
                        word[i] = ch;
                        if(st.find(word) != st.end()) { // word present in set
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i] = originalCh;
                }
            }
            lvl++;
        }

        // endWord can't be reached
        return 0;
    }
};


int main() {
    
    return 0;
}