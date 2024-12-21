// https://leetcode.com/contest/biweekly-contest-146/problems/count-subarrays-of-length-three-with-a-condition/
// Count Subarrays of Length Three with a Condition


class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 1; i < n - 1; i++) {
            int sum = (nums[i - 1] + nums[i + 1]) * 2;
            if (sum == nums[i]) count++;
        }
        return count;
    }
};