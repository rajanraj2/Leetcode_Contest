// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-ii/description/
// Zero Array Transformation II


class Solution {
public:
    bool helper(vector<int>& temp, vector<int>& arr, int& n) {
        int sum = 0;
        bool check = true;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            // int prev = temp[i];
            temp[i] += sum;
            if (temp[i] < 0) temp[i]= 0;
            
            if (temp[i] != 0) check = false;
            // temp[i] = prev;
            
        }
        return check;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size(), q = queries.size();
        vector<int> arr(n + 1, 0);
        int count = 0;
        if (helper(nums, arr, n)) return count;
        
        for (auto it : queries) {
            count++;
            int left = it[0];
            int right = it[1];
            arr[left] -= it[2];
            if (right + 1 < n) arr[right + 1] += it[2];
            
            if (helper(nums, arr, n)) return count;
        }

        return -1;
    }
};