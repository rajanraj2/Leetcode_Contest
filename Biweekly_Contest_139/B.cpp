// Link - https://leetcode.com/contest/biweekly-contest-139/problems/find-a-safe-walk-through-a-grid/submissions/1389998237/


class Solution {
private:
    int dfs(vector<vector<int>>& grid, int health, int x, int y, vector<vector<int>>& vis, vector<vector<int>>& memo) {
        int m = grid.size();
        int n = grid[0].size();
        if (x == m - 1 && y == n - 1) {
            return health;
        }

        if (memo[x][y] >= health) {
            return -1;
        }
        memo[x][y] = health;

        vector<int> arrx = {0, 1, 0, -1};
        vector<int> arry = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + arrx[i], ny = y + arry[i];
            if (nx < m && nx >= 0 && ny < n && ny >= 0 && vis[nx][ny] == 0 && grid[nx][ny] == 0) {
                vis[nx][ny] = 1;
                int ans = dfs(grid, health, nx, ny, vis, memo);
                if (ans > 0) return ans;
                vis[nx][ny] = 0;

            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + arrx[i], ny = y + arry[i];
            if (nx < m && nx >= 0 && ny < n && ny >= 0 && vis[nx][ny] == 0 && grid[nx][ny] == 1) {
                vis[nx][ny] = 1;
                int ans = dfs(grid, health - 1, nx, ny, vis, memo);
                if (ans > 0) return ans;
                vis[nx][ny] = 0;

            }
        }

        return -1;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        vector<vector<int>> memo(m, vector<int>(n, -1));

        vis[0][0] = 1;
        if (grid[0][0] == 1) health--;
        if (health <= 0) return false;

        if (dfs(grid, health, 0, 0, vis, memo) > 0) return true;
        else return false;
    }
};