// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/
// 3487. Maximum Unique Subarray Sum After Deletion


class Solution {
    public:
        int maxSum(vector<int>& nums) {
            unordered_set<int> st(nums.begin(), nums.end());
            int n = nums.size(), result = INT_MIN;
            bool flag = false;
            int maxi = INT_MIN, sum = 0;
            for (auto it : st) {
                if (it >= 0) {
                    flag = true;
                    sum += it;
                }
                else {
                    maxi = max(maxi, it);
                }
            }
            if (flag) {
                return sum;
            }
            return maxi;
        }
    };