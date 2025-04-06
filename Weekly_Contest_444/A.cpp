// https://leetcode.com/contest/weekly-contest-444/problems/minimum-pair-removal-to-sort-array-i/
// Minimum Pair Removal to Sort Array I


class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0, index;
        while (true) {
            int sum, mini = INT_MAX;
            bool flag = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i - 1] > nums[i]) {
                    flag = false;
                    break;
                }
            }
            if (nums.size() <= 1 || flag) return count;
            for (int i = 1; i < nums.size(); i++) {
                sum = nums[i - 1] + nums[i];
                if (sum < mini) {
                    mini = sum;
                    index = i;
                }
            }
            count++;
            nums[index - 1] += nums[index];
            nums.erase(nums.begin() + index);
        }
        return count;
    }
};