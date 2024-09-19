// 

#include<bits/stdc++.h>
using namespace std;


// method-0 : using Trie
class TrieNode {
public:
    TrieNode* childs[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            childs[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (temp->childs[idx] == NULL) {
                temp->childs[idx] = new TrieNode();
            }
            temp = temp->childs[idx];
        }
    }
};

class Solution {
public:
    int n;
    string target;
    vector<int> dp;

    int solve(int i, TrieNode* root) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        TrieNode* temp = root;
        int ans = INT_MAX;

        for (int j = i; j < n; j++) {
            int idx = target[j] - 'a';
            if (temp->childs[idx] == NULL) break;
            temp = temp->childs[idx];
            int t = solve(j + 1, root);
            if (t != INT_MAX) {
                ans = min(ans, t + 1);
            }
        }
        return dp[i] = ans;
    }

    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }

        n = target.size();
        this->target = target;
        dp = vector<int>(n, -1);

        int ans = solve(0, trie.root);
        return (ans == INT_MAX) ? -1 : ans;
    }
};


int main() {
    
    return 0;
}