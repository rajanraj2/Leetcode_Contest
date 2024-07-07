// Link - https://leetcode.com/contest/weekly-contest-405/problems/count-submatrices-with-equal-frequency-of-x-and-y/
// Count Submatrices With Equal Frequency of X and Y


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int endRow = 0; endRow < rows; ++endRow) {
            for (int endCol = 0; endCol < cols; ++endCol) {
                
                unordered_map<char, int> freq;
                
                for (int startRow = 0; startRow <= endRow; ++startRow) {
                    for (int startCol = 0; startCol <= endCol; ++startCol) {
                        char current = grid[startRow][startCol];
                        freq[current]++;
                    }
                }
                
                if (freq['X'] > 0 && freq['X'] == freq['Y']) {
                    count++;
                }
            }
        }
        
        return count;
    }
};