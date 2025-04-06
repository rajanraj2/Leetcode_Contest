// https://leetcode.com/contest/weekly-contest-444/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/
// Maximum Product of Subsequences With an Alternating Sum Equal to K


class Solution {
private:
    unordered_map<string, int> memo;
    
    void helper(int index, vector<int>& nums, int sum, long long mul,
                int k, int limit, long long& result, int pos) {
        if (index == nums.size()) return;
        
        string key = to_string(index) + "-" + to_string(sum) 
                     + "-" + to_string(mul) + "-" + to_string(pos);
        if (memo.count(key)) return;
        memo[key] = 1;

        helper(index + 1, nums, sum, mul, k, limit, result, pos);

        int new_sum = sum;
        if (pos % 2) new_sum -= nums[index];
        else new_sum += nums[index];
        
        long long new_mul = mul * nums[index];

        if (new_sum == k && new_mul <= limit) {
            result = max(result, new_mul);
        }

        // if (new_mul > limit) return;
        helper(index + 1, nums, new_sum, new_mul, k, limit, result, pos + 1);
    }

public:
    int maxProduct(vector<int>& nums, int k, int limit) {
        long long result = -1;
        helper(0, nums, 0, 1, k, limit, result, 0);
        return (result == -1 ? -1 : static_cast<int>(result));
    }
};
