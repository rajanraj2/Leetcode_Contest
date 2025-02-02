// https://leetcode.com/problems/maximum-and-minimum-sums-of-at-most-size-k-subsequences/description/
// 3428. Maximum and Minimum Sums of at Most Size K Subsequences


class Solution {
public:
    int mod = 1e9 + 7;
    void helper(int ind, vector<int>& nums, int k, int mini, int maxi, int &sum, int count) {
        if (count > k || ind >= nums.size()) {
            if (count > 0) {
                sum = (sum + (mini % mod) + (maxi % mod)) % mod;
            } 
            return;
        }
        helper(ind + 1, nums, k, mini, maxi, sum, count);
        int newmini = min(mini, nums[ind]);
        int newmaxi = max(maxi, nums[ind]);
        helper(ind + 1, nums, k, newmini, newmaxi, sum, count + 1);
        
    }

    int minMaxSums(vector<int>& nums, int k) {
        int sum = 0, n = nums.size();
        helper(0, nums, k, INT_MAX, INT_MIN, sum, 0);
        return sum;
    }
};