// 165. Compare Version Numbers
// LeetCode : https://leetcode.com/problems/compare-version-numbers/

/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i = 0, j = 0;
        int n1 = v1.length(), n2 = v2.length();
        while(i < n1 || j < n2) {
            string s1, s2;
            while(i < n1 && v1[i] != '.') s1 += v1[i], i++;
            if(i < n1 && v1[i] == '.') i++;
            while(j < n2 && v2[j] != '.') s2 += v2[j], j++;
            if(j < n2 && v2[j] == '.') j++;

            int num1 = s1.length() ? stoi(s1) : 0;
            int num2 = s2.length() ? stoi(s2) : 0;
            if(num1 < num2) return -1;
            else if (num1 > num2) return 1;
        }
        return 0;
    }
};