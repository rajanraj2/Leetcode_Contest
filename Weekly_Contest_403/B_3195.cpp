// Link - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// Find the Minimum Area to Cover All Ones


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result;
        pair<int, int> start = {-1, -1}, left = {INT_MAX, INT_MAX}, right = {-1, -1};
        pair<int, int> end;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (start == make_pair(-1, -1) && grid[i][j] == 1) {
                    start = {i, j};
                }
                if (j < left.second && grid[i][j] == 1) left.second = j;
                if (j > right.second && grid[i][j] == 1) right.second = j;
                if (grid[i][j] == 1) end = {i,j};
            }
        }
        int length = right.second - left.second + 1;
        result = (end.first - start.first + 1);
        return result * length;
    }
};