// Link - https://leetcode.com/problems/maximize-total-cost-of-alternating-subarrays/
// Maximize Total Cost of Alternating Subarrays

// Not complete solution

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        vector<int> check(n, -1);
        result += nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0 && nums[i - 1] >= 0) {
                result += -1 * nums[i];
                check[i] = 1;
            } 
            else if (nums[i] < 0 && nums[i - 1] < 0 && check[i - 1] != 1) {
                result += -1 * nums[i];
                check[i] = 1;
            }
            else {
                result += nums[i];
                check[i] = 1;
            }
        }
        return result;
    }
};