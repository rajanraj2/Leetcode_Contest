// Link - https://leetcode.com/contest/weekly-contest-405/problems/find-the-encrypted-string/
// Find the Encrypted String


class Solution {
public:
    string getEncryptedString(string s, int k) {
        string copy = s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            copy[i] = s[(i + k) % n];
        }
        return copy;
    }
};