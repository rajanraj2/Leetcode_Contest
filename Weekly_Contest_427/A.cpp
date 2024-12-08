// https://leetcode.com/problems/transformed-array/
// Transformed Array


class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            int index = 0;
            if (nums[i] > 0) {
                index = (i + nums[i]) % n;
                // result[i] = nums[(i + nums[i]) % n];
            }
            else if (nums[i] < 0) {
                index = ((i + nums[i]) % n + n) % n;
                // result[i] = nums[((i + n + nums[i]) % n)];
            }
            else {
                result[i] = 0;
                continue;
            }
            result[i] = nums[index];
        }
        return result;
    }
};