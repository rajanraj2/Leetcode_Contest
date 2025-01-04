// https://leetcode.com/contest/biweekly-contest-147/problems/substring-matching-pattern/description/
// Substring Matching Pattern


class Solution {
public:
    bool hasMatch(string s, string p) {
        int part;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '*') part = i;
        }
        string first = p.substr(0, part);
        string second = p.substr(part + 1, p.size() - part - 1);
        int fir = first.size(), sec = second.size();

        bool flag = false;
        int ind = 0;
        if (fir == 0 && sec == 0) return true;
        
        if (fir > 0) {
            for (int i = 0; i <= s.size() - fir; i++) {
                if (!flag && i <= (s.size() - fir) && s.substr(i, fir) == first) {
                    flag = true;
                    ind = i + fir;
                    continue;
                }
            }
        } 
        if (fir > 0 && !flag) return false;

        for (int i = ind; i <= s.size() - sec; i++) {
            if (s.substr(i, sec) == second) {
                return true;
            }
        }
        if (sec <= 0 && flag) return true; 
        return false;
    }
}