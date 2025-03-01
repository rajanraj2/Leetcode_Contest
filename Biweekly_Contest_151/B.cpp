// https://leetcode.com/problems/find-the-number-of-copy-arrays/
// 3468. Find the Number of Copy Arrays


class Solution {
    public:
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int result = INT_MAX;
            int n = original.size();
            vector<int> next(2), prev(2);
            int d;
            prev = bounds[0];
            
            for (int i = 1; i < n; i++) {
                d = original[i] - original[i - 1];
                next[0] = prev[0] + d;
                next[1] = prev[1] + d;
    
                int start = max(bounds[i][0], next[0]);
                int end = min(bounds[i][1], next[1]);
                int sz = end - start + 1;
                sz = max(0, sz);
                result = min(result, sz);
                prev = {start, end};
            }
            return max(0, result);
        }
    };