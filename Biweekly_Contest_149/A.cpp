// https://leetcode.com/contest/biweekly-contest-149/problems/find-valid-pair-of-adjacent-digits-in-string/
// Find Valid Pair of Adjacent Digits in String


class Solution {
public:
    string findValidPair(string s) {
        string result = "";
        vector<int> arr(10, 0);
        for (int i = 0; i < s.size(); i++) {
            int val = s[i] - '0';
            arr[val]++; 
        }

        for (int i = 1; i < s.size(); i++) {
            int prev = s[i - 1] - '0';
            int curr = s[i] - '0';
            if (arr[prev] == prev && arr[curr] == curr && prev != curr) {
                result += to_string(prev);
                result += to_string(curr);
                return result;
            }
        }
        return result;
    }
};