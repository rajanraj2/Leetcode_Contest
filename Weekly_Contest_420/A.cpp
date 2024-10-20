// Link - https://leetcode.com/contest/weekly-contest-420/problems/find-the-sequence-of-strings-appeared-on-the-screen/description/
// Find the Sequence of Strings Appeared on the Screen


class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string s = "";
        int index = 0;
        while (s != target) {
            s += "a";
            while (s[index] != target[index]) {
                result.push_back(s);
                s[index] = s[index] + 1;
            }
            index++;
            result.push_back(s);
        }
        return result;
    }
};