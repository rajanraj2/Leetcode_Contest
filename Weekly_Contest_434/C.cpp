// https://leetcode.com/problems/maximum-frequency-after-subarray-operation/description/
// 3434. Maximum Frequency After Subarray Operation


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = count(nums.begin(), nums.end(), k);
        int maxi = 0;
        for (int i = 1; i <= 50; i++) {
            if (i == k) continue;
            int curr = 0, cnt = 0;
            for (int it : nums) {
                curr += i == it ? 1 : it == k ? -1 : 0;
                curr = max(curr, 0);
                cnt = max(cnt, curr);
            }
            maxi = max(maxi, cnt);
        }
        return ans + maxi;
    }
};