// Floyd Warshall Algorithm (MSSP: Multi Source Shortest Path)
// GFG : https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

/*
TC : O(V^3)
SC : O(V^2), as we are using the 'input matrix' to solve our problem
*/

#include<iostream>
using namespace std;


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    
	    // NOT NECESSARY (changing -1 to INF)
	    int n = matrix.size();
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == -1) {
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
	    
	    // Floyd Warshall Algorithm
	    for(int via = 0; via < n; via++) { // TC: O(V^3)
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
	                matrix[i][j] = min(matrix[i][j], 
                                       matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    
	    // check for negative cylcle
	    for(int i = 0; i < n; i++) {
	        if(matrix[i][i] < 0) {
	            cout << "Negative Cycle is Present"; // OR return -1;...
	        }
	    }
	    
	    // NOT NECESSARY (reverting changes INF to -1)
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == 1e9) {
	                matrix[i][j] = -1;
	            }
	        }
	    }
	}
};


int main() {
    
    return 0;
}