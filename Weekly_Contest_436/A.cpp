// https://leetcode.com/contest/weekly-contest-436/problems/sort-matrix-by-diagonals/
// 3446. Sort Matrix by Diagonals


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int> (n, 0));
        
        for (int i = 0; i < n; i++) {
            int j = 0, row = i;
            vector<int> arr;
            while (row < n & j < n) arr.push_back(grid[row++][j++]);
            row--;
            j--;
            sort(arr.rbegin(), arr.rend());
            while (row >= i && j >= 0) result[row--][j--] = arr[j];
        }

        for (int j = 1; j < n; j++) {
            int i = 0, col = j;
            vector<int> arr;
            while (i < n && col < n) arr.push_back(grid[i++][col++]);
            i--;
            col--;
            sort(arr.begin(), arr.end());
            while (i >= 0 && col >= j) result[i--][col--] = arr[i];
        }        
        return result;
    }
};