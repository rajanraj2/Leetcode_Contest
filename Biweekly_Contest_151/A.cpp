// https://leetcode.com/problems/transform-array-by-parity/
// 3467. Transform Array by Parity


class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size(), count = 0;
        vector<int> result(n, 1);
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) count++;
        }

        for (int i = 0; i < count; i++) {
            result[i] = 0;
        }
        return result;
    }
};