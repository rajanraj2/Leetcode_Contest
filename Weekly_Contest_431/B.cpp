// https://leetcode.com/contest/weekly-contest-431/problems/find-mirror-score-of-a-string/
// Find Mirror Score of a String


class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> mpp;
        mpp[s[0]].push_back(0);
        long long result = 0;

        for (int i = 1; i < n; i++) {
            char ch = s[i];
            char mir;
            if (ch > 'm') mir = 'a' + ('z' - ch);
            else mir = 'z' - (ch - 'a');
            int len = mpp[mir].size();
            if (len > 0) {
                int ind = mpp[mir].back();
                result += (i - ind);
                mpp[mir].pop_back();
            }
            else {
                mpp[ch].push_back(i);
            }
        }
        return result;
    }
};