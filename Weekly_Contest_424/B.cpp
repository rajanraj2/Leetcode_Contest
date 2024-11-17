// https://leetcode.com/contest/weekly-contest-424/problems/zero-array-transformation-i/description/'
// Zero Array Transformation I


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        vector<int> arr(n + 1, 0);
        for (auto it : queries) {
            int left = it[0];
            int right = it[1];
            arr[left]--;
            if (right + 1 < n) arr[right + 1]++;
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            nums[i] += sum;
            if (nums[i] < 0) nums[i] = 0;
            if (nums[i] != 0) return false;
        }

        return true;
    }
};