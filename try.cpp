class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();

        // Find next greater element for every index in heights
        vector<int> nextGreater(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[i] >= heights[s.top()]) s.pop();
            if (!s.empty()) nextGreater[i] = s.top();
            s.push(i);
        }

        unordered_map<long long, int> memo;

        // Hash function for pair<int, int>
        auto hashKey = [](int a, int b) -> long long {
            return static_cast<long long>(a) * 1e5 + b;  // Ensures unique key for (a, b)
        };

        int m = queries.size();
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);

            // Check memoization
            long long key = hashKey(a, b);
            if (memo.find(key) != memo.end()) {
                ans[i] = memo[key];
                continue;
            }

            int j = b;
            if (a == b || heights[a] < heights[b]) {
                ans[i] = j;
                memo[key] = j;
                continue;
            }
            if (a != b && heights[a] == heights[b]) j = nextGreater[j];
            while (j != -1 && j < n) {
                if (heights[j] > heights[a] && heights[j] >= heights[b]) {
                    ans[i] = j;  // Found a valid building
                    memo[key] = j;
                    break;
                }
                j = nextGreater[j];
            }

            // If no valid building is found, memoize -1
            if (ans[i] == -1) {
                memo[key] = -1;
            }
        }
        return ans;
    }
};
