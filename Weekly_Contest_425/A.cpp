// https://leetcode.com/contest/weekly-contest-425/problems/minimum-positive-sum-subarray/
// Minimum Positive Sum Subarray


class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size(), start = 0; 
        int result = INT_MAX, sum = 0;

        for (int i = l; i <= r; i++) {
            int sum = 0;
            for (int j = 0; j < i; j++) sum += nums[j];

            if (sum > 0) result = min(result, sum);
            for (int j = i; j < n; j++) {
                sum += nums[j] - nums[j - i];
                if (sum > 0) result = min(sum, result);
            }
            
            // while (end - start + 1 > r) {
            //     sum -= nums[start];
            //     start++;
            // }
            // if (end - start + 1 >= l && sum > 0) result = min(result, sum);
        }

        if (result == INT_MAX) return -1;
        else return result;
    }
};