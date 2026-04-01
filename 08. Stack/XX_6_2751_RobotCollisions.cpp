// 2751. Robot Collisions
// LeetCode : https://leetcode.com/problems/robot-collisions/description/


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // can't sort positions[], hence creating indices[]
        vector<int> indices(n), ans;
        for(int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // sorting indices acc to positions[]
        sort(indices.begin(), indices.end(), [&](int i1, int i2) {return positions[i1] < positions[i2];});

        stack<int> st;
        for(int& idx : indices) {
            if(directions[idx] == 'R') {
                st.push(idx);
            }
            else {
                while(!st.empty() && healths[idx] > 0) {
                    int top = st.top();
                    st.pop();
                    if(healths[top] == healths[idx]) {
                        healths[top] = 0;
                        healths[idx] = 0;
                    }
                    else if(healths[top] < healths[idx]) {
                        healths[top] = 0;
                        healths[idx]--;
                    }
                    else {
                        healths[top]--;
                        healths[idx] = 0;
                        st.push(top);
                    }
                }
            }
        }

        // storing robots whose health > 0
        for(auto& health : healths) {
            if(health > 0) ans.push_back(health);
        }

        return ans;
    }
};