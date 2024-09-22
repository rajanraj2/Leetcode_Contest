// Link - https://leetcode.com/contest/weekly-contest-416/problems/report-spam-message/
// Report Spam Message


class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        set<string> st(bannedWords.begin(), bannedWords.end());
        int count = 0;

        for (string it : message) {
            if (st.find(it) != st.end()) count++;
        }

        if (count >= 2) return true;
        else return false;
    }
};