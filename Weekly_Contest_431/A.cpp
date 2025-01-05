// https://leetcode.com/contest/weekly-contest-431/problems/maximum-subarray-with-equal-products/
// Maximum Subarray with Equal Products


class Solution {
public:
    long long gcd (long long x, long long y) {
        while (y != 0) {
            long long t = y;
            y = x % y;
            x = t;
        }
        return x;
    }

    long long lcm(long long x, long long y) {
        return (x / gcd(x, y)) * y;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int result = 1;
        
        for (int i = 0; i < n; i++) {
            long long prod = nums[i], l = nums[i], g = nums[i];
            int val = 1;
            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                g = gcd(nums[j], g);
                l = lcm(nums[j], l);
                if (prod == l * g) val = j - i + 1;
                result = max(result, val);
            }
        }
        return result;
    }
};