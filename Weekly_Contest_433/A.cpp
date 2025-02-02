// https://leetcode.com/problems/sum-of-variable-length-subarrays/
// 3427. Sum of Variable Length Subarrays


class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0, n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] += pre[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            int start = max(0, i - nums[i]);
            sum += pre[i];
            if (start > 0) sum -= pre[start - 1];
        }
        return sum;
    }
};