// https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
// 3512. Minimum Operations to Make Array Sum Divisible by K


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int result = sum % k;
        return result;
    }
};