// Link - https://leetcode.com/contest/weekly-contest-420/problems/count-substrings-with-k-frequency-characters-i/description/
// Count Substrings with K Frequency Characters


class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            map<char, int> mpp;
            int maxi = 0;
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;
                if (mpp[s[j]] > maxi) maxi = mpp[s[j]];
                if (maxi >= k) {
                    result += n - j;
                    break;
                }
            }
        }

        return result;
    }
};