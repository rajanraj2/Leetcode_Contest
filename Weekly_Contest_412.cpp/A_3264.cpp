class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; i++) {
            int mini = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[mini]) {
                    mini = i;
                }
            }
            nums[mini] *= multiplier;
        }
        return nums;
    }
};