// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/
// 3463. Check If Digits Are Equal in String After Operations II


// TLE

class Solution {
public:
    bool helper(string s) {
        vector<int> arr;
        for (char ch : s) arr.push_back(ch - '0');

        while (arr.size() > 2) {
            int sz = arr.size();
            for (int i = 0; i < sz - 1; i++) arr[i] = (arr[i] + arr[i + 1]) % 10;
            arr.pop_back();
        }

        if (arr.size() == 2 && arr[0] == arr[1]) return true;
        return false;
    }

    bool hasSameDigits(string s) {
        return helper(s);
    }
};