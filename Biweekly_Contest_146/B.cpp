// https://leetcode.com/contest/biweekly-contest-146/problems/count-paths-with-the-given-xor-value/
// Count Paths with given XOR value


class Solution {
int mod = 1e9 + 7;
private:
     unordered_map<int, unordered_map<int, unordered_map<int, int>>> dp;
        
     int helper(vector<vector<int>>& grid, int i, int j, int k, int val, int n, int m) {
         if (i == n - 1 && j == m - 1) {
             val = val ^ grid[i][j];
             if (k == val) return 1;
             return 0;
         }
         if (dp[i][j].count(val)) {
             return dp[i][j][val];
         }
         int value = 0;

         
         val = val ^ grid[i][j];
         if (i <= n - 2) {
             value = (value + helper(grid, i + 1, j, k, val, n, m)) % mod;
         }
         if (j <= m - 2) {
             value = value + (helper(grid, i, j + 1, k, val, n, m)) % mod;
         }
         return dp[i][j][val] = value;
     }

public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int i = 0, j = 0, val = 0;
        int result = helper(grid, i, j, k, val, n, m);
        if (result == 0) return result;
        return result - 1;
    }
};