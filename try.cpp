#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int findBalancedServers(vector<int>& capacity) {
    int n = capacity.size();

    // Step 1: Calculate prefix sum
    vector<int> prefixSum(n, 0);
    prefixSum[0] = capacity[0];
    for (int j = 1; j < n; ++j) {
        prefixSum[j] = capacity[j] + prefixSum[j - 1];
    }

    int stable = 0;
    vector<pair<int, int>> check;
    unordered_map<int, vector<int>> d;

    // Step 2: Iterate through the array
    for (int i = 0; i < n; ++i) {
        int num = capacity[i];

        if (d.find(num) != d.end()) {
            stack<int> stack;
            vector<int>& indices = d[num];
            bool found = false;

            while (!indices.empty()) {
                int curI = indices.back();
                indices.pop_back();

                if (i - curI + 1 >= 3) {
                    found = true;
                    if (prefixSum[i - 1] - prefixSum[curI] == num) {
                        check.push_back({curI, i});
                        stable++;
                    }
                    break;
                }

                stack.push(curI);
            }

            // Restore the remaining indices
            while (!stack.empty()) {
                indices.push_back(stack.top());
                stack.pop();
            }
        }

        d[num].push_back(i);
    }

    // Print the valid indices (optional, for debugging)
    cout << "valid indices: ";
    for (const auto& p : check) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return stable;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> capacity(n);
    for(int i = 0; i < n; i++) {
        cin >> capacity[i];
    }

    cout << findBalancedServers(capacity) << endl;
    return 0;
}
