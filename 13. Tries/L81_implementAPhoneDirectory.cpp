// Implement a phone directory
// CodeStudio : https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666

/*
TC : O(n * m^2)
SC : O(m * n)
*/

#include<iostream>
#include<string>
using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26]; // 'a' to 'z'
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
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
            root->children[index] = child;
        }

        // recursion
        insertUtil(child, word.substr(1));
    }

    // TC : O(l)
    void insertWord(string word) {
        insertUtil(root, word);
    }

    void storeSuggestions(TrieNode* curr, string prefix, vector<string> &temp) {
        if(curr->isTerminal) {
            temp.push_back(prefix);
            // HW : why we removed return keyword from here ?
        }

        for(char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch-'a'];

            if(next != NULL) {
                prefix.push_back(ch);
                storeSuggestions(next, prefix, temp);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestions(string queryStr) {
        TrieNode* prev = root;
        vector<vector<string>> ans;
        string prefix = "";
        for(int i = 0; i < queryStr.length(); i++) {
            char lastCh = queryStr[i];
            prefix.push_back(lastCh);

            // check for lastCh
            TrieNode* curr = prev->children[lastCh - 'a'];

            // if not found
            if(curr == NULL) {
                break;
            }

            // if found
            vector<string> temp;
            storeSuggestions(curr, prefix, temp); // storing suggestions in 'temp' for a given prefix

            ans.push_back(temp);
            temp.clear();

            prev = curr;
        }
        return ans;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    // Write your code here.

    // creation of Trie
    Trie *t = new Trie();

    // insert all contacts in Trie
    for(int i = 0; i < contactList.size(); i++) {
        string str = contactList[i];
        t->insertWord(str);
    }

    // return ans
    return t->getSuggestions(queryStr);
}

int main() {
    
    return 0;
}