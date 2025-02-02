// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/
// 3442. Maximum Difference Between Even and Odd Frequency I


class Solution {
public:
    int maxDifference(string s) {
        int result = 0;
        vector<int> arr(26, 0);
        for (char ch : s) arr[ch - 'a']++;
        int odd = 0, even = INT_MAX;
        for (int it : arr) {
            if (it % 2 == 1) odd = max(odd, it);
            else if (it != 0) even = min(even, it);
        }
        return odd - even;
    }
};