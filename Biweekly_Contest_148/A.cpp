// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/
// 3423. Maximum Difference Between Adjacent Elements in a Circular Array


class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), result = 0;
        for (int i = 1; i < n; i++) {
            result = max(result, abs(nums[i] - nums[i - 1]));
        }
        result = max(result, abs(nums[n - 1] - nums[0]));
        return result;
    }
};