// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
// 3461. Check If Digits Are Equal in String After Operations I


class Solution {
    public:
        string helper(string s) {
            int n = s.size();
            string ans = "";
            for (int i = 0; i < n - 1; i++) {
                ans += (((s[i] - '0') + (s[i + 1] - '0')) % 10) + '0';
            }
            return ans;
        }
    
        bool hasSameDigits(string s) {
            while (s.size() > 2) {
                s = helper(s);
            }
            if (s.size() == 2 && s[0] == s[1]) return true;
            return false;
        }
    };