// Link - https://leetcode.com/problems/find-the-occurrence-of-first-almost-equal-substring/
// Find the Occurrence of First Almost Equal Substring


// TLE

class Solution {
public:
    int minStartingIndex(string s, string pattern) {
        int n = pattern.size();
        int m = s.size();
        int result = -1;

        for (int i = 0; i < m; i++) {
            int j = i;
            bool check = false;
            for (int k = 0; k < n; k++) {
                if (j >= m) break;  
                if (pattern[k] != s[j]) {
                    if (check) break;
                    check = true;
                }
                j++;
            }
            if (j - i == n) {
                result = i;
                break;
            }
        }

        return result;
    }
};