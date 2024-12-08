// https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
// Minimum Operations to Make Array Values Equal to K


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int prev = nums[0];
        int result = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < k) {
                result = -1;
                break;
            }
            if (nums[i] != prev) result++;
            prev = nums[i];
        }
        
        if (result != -1 && k < nums.back()) result ++;
        if (nums.size() <= 1) {
            if (nums[0] < k) result = -1;
            else if (nums[0] == k) result = 0;
            else result = 1;
        }
        return result;
    }
};