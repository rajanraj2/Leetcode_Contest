// https://leetcode.com/problems/shift-distance-between-two-strings/
// Shift distance between two strings


class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long result = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                int a = s[i] - 'a';
                int b = t[i] - 'a';
                int diff = (b - a + 26) % 26;
                int diff2 = (a - b + 26) % 26;
                // diff = (diff + 26) % 26;
                // diff = min(diff, 26 - diff);
                
                long long next = 0, prev = 0;

                for (int j = 0; j < diff; j++) {
                    next += nextCost[(a + j) % 26];
                }

                for (int j = 0; j < diff2; j++) {
                    prev += previousCost[(a - j + 26) % 26];
                }

                result += min(next, prev);
                
                // if (diff < 0) diff *= -1;

                
                // next = (diff) * nextCost[a];
                // prev = (diff) * previousCost[a];
                

                // if (diff2 < 0) diff *= -1;
                // next2 = (diff2) * nextCost[a];
                // prev2 = (diff2) * previousCost[a];
                
                // result += min(next, prev);
                // cout << next << " " << prev << endl;
            }
        }
        return result;
    }
};