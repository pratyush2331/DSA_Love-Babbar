// 2185. Counting Words With a Given Prefix
// LeetCode : https://leetcode.com/problems/counting-words-with-a-given-prefix/

#include<bits/stdc++.h>
using namespace std;


// method-2 : trie
/*
TC : O(n.m + p)
SC : O(n.m)
*/
class TrieNode {
public:
    char data;
    TrieNode* children[26]; // 'a' to 'z'
    int freq; // IMP

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        freq = 0; // IMP
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string& word) {
        TrieNode* current = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(current->children[index] == NULL) {
                current->children[index] = new TrieNode(ch);
            }
            current = current->children[index];
            current->freq++; // IMP
        }
    }

    int cntPref(string& prefix) {
        TrieNode* current = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(current->children[index] == NULL) {
                return 0; // IMP
            }
            current = current->children[index];
        }
        return current->freq; // IMP
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie* t = new Trie();
        for(auto& word : words) {
            t->insertWord(word);
        }

        return t->cntPref(pref);
    }
};


// Method - 1
/*
TC : O(n * m)
SC : O(1)
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto& word : words) if(word.find(pref) == 0) cnt++;
        return cnt;
    }
};


// Method - 0
/*
TC : O(n * m)
SC : O(1)
*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto& word : words) {
            if(word.size() < pref.size()) continue;
            int i;
            for(i = 0; i < pref.size() && word[i] == pref[i]; i++);
            if(i == pref.size()) cnt++;
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}