// https://leetcode.com/problems/paint-house-iv/
// 3429. Paint House IV


class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<long long>> dp(n, vector<long long> (3, LLONG_MAX));
        long long result = LLONG_MAX;

        for (int i = 0; i < 3; i++) dp[0][i] = cost[0][i];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j != k) dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][k]);
                    
                }
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == k) dp[n - 1][j] = LLONG_MAX;
                }
            }
        }
        result = min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
        return result;
    }
};