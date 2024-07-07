// Link - https://leetcode.com/contest/weekly-contest-405/problems/generate-binary-strings-without-adjacent-zeros/
// Generate Binary Strings Without Adjacent Zeros


class Solution {
private:
    void helper(string s, vector<string>& result, int n) {
        if (s.size() >= n) {
            result.push_back(s);
            return;
        }
        if (s.size() == 0 || s[s.size() - 1] != '0' ) {
            s.push_back('0');
            helper(s, result, n);
            s.pop_back();
        }
        s.push_back('1');
        helper(s, result, n);
    } 

public:
    vector<string> validStrings(int n) {
        vector<string> result;
        string s = "";
        helper(s, result, n);
        return result;
    }
};