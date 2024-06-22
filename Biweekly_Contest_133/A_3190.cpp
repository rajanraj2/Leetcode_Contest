// Link - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
// Find Minimum Operations to Make All Elements Divisible by Three


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 3 != 0) {
                result++;
            }
        }
        return result;
    }
};