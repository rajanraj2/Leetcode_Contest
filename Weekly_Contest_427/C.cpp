// https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/
// Maximum Subarray Sum with Length Divisible by k


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        long long result = LLONG_MIN;
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + nums[i];
        for (int i = 0; i < n; i++) {
            int index = i + k - 1;
            while (index < n) {
                long long sum = pre[index];
                // cout << "i : " << i << endl;
                if (i != 0) sum -= pre[i - 1];
                // cout << sum << endl;
                result = max(result, sum);
                index += k;
            }
        }
        return result;
    }
};