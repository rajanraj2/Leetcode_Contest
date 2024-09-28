// Link - https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/
// Minimum Element After Replacement With Digit Sum


class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (int i : nums) {
            int sum = 0;
            while (i > 0) {
                sum += i % 10;
                i = i / 10;
            }
            result = min(result, sum);
        }
        return result;
    }
};