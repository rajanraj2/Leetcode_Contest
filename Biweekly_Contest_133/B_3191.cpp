// Link - https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/
// Minimum Operations to Make Binary Array Elements Equal to One


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0, result = 0;
        while (count < n - 2) {
            if (nums[count] == 0) {
                result++;
                nums[count] = 1;
                if (nums[count + 1] == 1) nums[count + 1] = 0;
                else nums[count + 1] = 1; 

                if (nums[count + 2] == 1) nums[count + 2] = 0;
                else nums[count + 2] = 1; 
            }
            count++;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }
        return result;
    }
};