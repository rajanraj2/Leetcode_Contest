// https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/
// 3432. Count Partitions with Even Sum Difference


class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
            sum += nums[i];
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int diff = pre[i] - (sum - pre[i]);
            if (diff % 2 == 0) count++;
        }
        return count;
    }
};