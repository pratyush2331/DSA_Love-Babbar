// 166. Fraction to Recurring Decimal
// LeetCode : https://leetcode.com/problems/fraction-to-recurring-decimal/\

/*
TC : O(n)
SC : O(n)
*/
using ll = long long;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // case-1 : numerator is 0
        if (numerator == 0) return "0";

        string res;
        // case-2 : +/- signs
        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        // taking abs of 'num' and 'den'
        ll num = llabs(numerator);
        ll den = llabs(denominator);

        // case-3 : handle integral part
        res += to_string(num / den);
        long long rem = num % den;
        if (rem == 0) return res;

        // add decimal '.'
        res += ".";

        // case-4 : handle decimal part
        // Map remainder -> position in result
        unordered_map<long long, int> mp;
        while(rem != 0) {
            if (mp.find(rem) != mp.end()) {
                // Insert '(' at the stored position
                res.insert(mp[rem], "(");
                res += ")";
                break;
            }
            mp[rem] = res.size();
            
            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }
        return res;
    }
};