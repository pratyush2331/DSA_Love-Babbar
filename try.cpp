// Power Set

#include<iostream>
using namespace std;

vector<string> subsequences(string str) {
	vector<string> ans;

	int n = str.size();
	for(int num = 0; num < (1<<n); num++) {
		string sub = "";
		for(int i = 0; i < n; i++) {
			if(num & (1<<i)) {
				sub += str[i];
			}
		}

		if(sub != "")
			ans.push_back(sub);
	}

	return ans;
}

int main() {
	
	return 0;
}