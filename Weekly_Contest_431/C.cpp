// https://leetcode.com/contest/weekly-contest-431/problems/maximum-coins-from-k-consecutive-bags/
// Maximum Coins From K Consecutive Bags 


class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        long long result = 0;
        sort(coins.begin(), coins.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int l = coins[0][1] - coins[0][0] + 1;
        int prevl = l;
        long long prevVal = coins[0][2];
        if (l >= k) {
            result  = k * coins[i][2];
        }
        else result = l * coins[i][2];

        for (int i = 1; i < coins.size(); i++) {
            long long val = 0;
            
            if (coins[i - 1][1] + 1 == coins[i][0]) {
                int len = coins[i][1] - coins[i][0] + 1;
                if (len >= k) {
                    val = k * coins[i][2];
                }
                long long val2, val3;
                if (prevl >= k) {
                    val2 = (k - 1) * prevVal; 
                    val2 += coins[i][2];
                }
                if (len < k) {
                    val3 += 
                }
            } 
            
        }
    }
};