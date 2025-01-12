// https://leetcode.com/problems/zigzag-grid-traversal-with-skip/
// Zigzag Grid Traversal With Skip


class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; j += 2) result.push_back(grid[i][j]); 
            }
            else {
                int k;
                if (m % 2 == 1) k = m - 2;
                else k = m - 1;
                for (int j = k; j >= 0; j -= 2) result.push_back(grid[i][j]);
            }
        }
        return result;
    }
};