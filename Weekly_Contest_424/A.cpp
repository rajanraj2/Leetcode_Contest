// https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/
// Make array elements equal to zero


class Solution {
private:
    int helper(vector<int> arr, int i, int n, int check) {
        while (i >= 0 && i < n) {
            if (arr[i] != 0) {
                arr[i]--;
                check = !check;
            }
            if (check) i++;
            else i--;
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) return false;
        }
        return true;
    }

public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (helper(nums, i, n, true)) result++;
                if (helper(nums, i, n, false)) result++;
            }
        }
        return result;
    }
};