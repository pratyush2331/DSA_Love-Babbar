// 14. Longest Common Prefix
// LeetCode : https://leetcode.com/problems/longest-common-prefix/

#include<iostream>
#include<string>
using namespace std;

// Approach - 1
// TC : O(n*m), SC : O(n*m);     n--> total no. of strings, m --> length of common prefix
class TrieNode {
    public:
    char data;
    TrieNode* children[26]; // consists of only lowercase English letters
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word) {
        // base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // assumption - word will be in CAPS
        int index = word[0] - 'a';
        TrieNode* child;
        // present
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        // absent
        else {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    // TC : O(l)
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if(root->childCount == 1 && root->isTerminal == false) {
                ans.push_back(ch);
                // aage badhjao
                int index = ch - 'a';
                root = root->children[index];
            }
            else {
                break;
            }
        }
    }
};

class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie('\0');

        // insert kardo all string into trie
        int n = strs.size();
        for(int i = 0; i < n; i++) {
            t->insertWord(strs[i]);
        }

        string first = strs[0];
        string ans = "";

        t->lcp(first, ans);

        return ans;
    }
};



// Approach - 2
// TC : O(n*m), SC : O(m);     n--> total no. of strings, m --> length of common prefix
/*
class Solution {
    public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        // for traversaing all characters of first string
        for(int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;
            // for comparing 'ch' with rest of the strings
            for(int j = 1; j < n; j++) {
                // not match
                if(strs[j].size() < i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            if(match == false) {
                break;
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
*/

int main() {
    
    return 0;
}