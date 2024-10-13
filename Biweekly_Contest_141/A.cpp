// Link - https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/
// Construct the Minimum Bitwise OR Array I


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j + 1)) == nums[i]) {
                    result[i] = j;
                    break;
                }
            }
        }
        return result;
    }
};
