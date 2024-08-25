// Link - https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
// Find the power of k size subarrays I


class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            bool check = true;
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j] + 1 != nums[j + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                int maxi = *max_element(nums.begin() + i, nums.begin() + i + k);
                result.push_back(maxi);
            }
            else {
                result.push_back(-1);
            }
        }

        return result;
    }
};