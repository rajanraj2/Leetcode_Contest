// Link - https://leetcode.com/contest/weekly-contest-406/problems/lexicographically-smallest-string-after-a-swap/
// LexicoGraphically Smallest String After a Swap


class Solution {
public:
    string getSmallestString(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] % 2 == 0 && s[i + 1] % 2 == 0 && s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                break;
            }
            if (s[i] % 2 == 1 && s[i + 1] % 2 == 1 && s[i] > s[i + 1]) {
                swap(s[i], s[i + 1]);
                break;
            }
        }r
        return s;
    }
};