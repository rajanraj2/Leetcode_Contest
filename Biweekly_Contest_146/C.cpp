// https://leetcode.com/contest/biweekly-contest-146/problems/check-if-grid-can-be-cut-into-sections/
// Check if Grid Can Be Cut Into Sections


class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        bool result = false;
        int count = 0;
        
        vector<pair<int, int> a(n), b(n), c(n), d(n);
        int i = 0;
        for (auto it : rectangles) {
            a[i] = {i, it[1]};
            b[i] = {i, it[3]};
            c[i] = {i, it[0]};
            d[i] = {i, it[2]};
            i++;
        }
        sort()
        for (int i = 1; i < n; i++) {
            if (b[i] )
        }
        
    }
};©leetcode