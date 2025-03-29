// https://leetcode.com/problems/maximize-active-section-with-trade-i/
// 3499. Maximize Active Section with Trade I


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int count = 0, maxi = 0, one = 0;
        for (auto it : s) {
            if (it == '1') count++;
        }
        s = "1" + s + "1";
        maxi = max(maxi, count);
        count = 0;

        int left = 1;
        while (left < s.size() && s[left] == '1') left++;
        int right = left;
        bool after = false;
        
        while (right < s.size()) {
            if (s[right] == '0') {
                if (one > 0) {
                    count = max(count, right - left - one + 1); 
                    after = true;
                }
            }
            else if (s[right] == '1') {
                if (after) {
                    while (one) {
                        if (s[left] == '1') one--;
                        left++;
                    }
                    after = false;
                }
                one++;
            }
            right++;
        }

        int result = max(maxi, maxi + count);
        return result;    
    }
};