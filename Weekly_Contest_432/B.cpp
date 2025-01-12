// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
// Maximum Amount of Money Robot Can Earn


class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

        if (coins[0][0] >= 0) dp[0][0][0] = coins[0][0];
        else dp[0][0][0] = -abs(coins[0][0]);
        if (coins[0][0] < 0) dp[0][0][1] = 0;
        int result = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 3; k ++) {
                    if (dp[i][j][k] == INT_MIN) continue;

                    if (i + 1 < n) {
                        int down = coins[i + 1][j];
                        if (down >= 0) dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + down);
                        else {    
                            if (k < 2) dp[i + 1][j][k + 1] = max(dp[i + 1][j][k + 1], dp[i][j][k]);
                            dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + down);
                        }
                    }

                    if (j + 1 < m) {
                        int right = coins[i][j + 1];
                        if (right >= 0) dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + right);
                        else {
                            if (k < 2) dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i][j][k]);
                            dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + right);
                        }
                    }

                    if (i == n - 1 && j == m - 1) result = max(result, dp[i][j][k]);
                }
                
            }
        }
        return result;
    }
};