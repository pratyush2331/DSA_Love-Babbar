// First non-repeating character in a stream
// GFG : https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include<iostream>
using namespace std;

class Solution {
	public:
	string FirstNonRepeating(string A){
		string ans;
		
		unordered_map<char, int> count;
		queue<int> q;
		
		for(int i = 0; i < A.length(); i++) {
			char ch = A[i];
			
			// increase count
			count[ch]++;
			
			// q me push karo
			q.push(ch);
			
			while(!q.empty()) {
				if(count[q.front()] > 1) {
					// repeating character
					q.pop();
				}
				else {
					// non-repeating character mil gaya... ans me store krke break krlo
					ans.push_back(q.front());
					break;
				}
			}
			
			if(q.empty()) {
				ans.push_back('#');
			}
		}
		
		return ans;
	}
};

int main() {
	
	return 0;
}