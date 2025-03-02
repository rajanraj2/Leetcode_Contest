// https://leetcode.com/problems/maximum-sum-with-at-most-k-elements/
// 3462. Maximum Sum With at Most K Elements


class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            long long result = 0;
            int n = grid.size(), m = grid[0].size();
            int sz = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            priority_queue<int> pq2;
            
            for (int i = 0; i < n; i++) {
                sz = limits[i];
                for (int j = 0; j < m; j++) {
                    pq.push(grid[i][j]);
                    if (pq.size() > sz) pq.pop();
                }
                while (pq.size() > 0) {
                    pq2.push(pq.top());
                    pq.pop();
                }
            }
    
            while (k--) {
                result += pq2.top();
                pq2.pop();
                if (pq2.size() <= 0) break;
            }
            return result;
        }
    };