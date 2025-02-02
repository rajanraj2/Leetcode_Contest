// https://leetcode.com/problems/minimum-cost-to-make-arrays-identical/
// 3424. Minimum Cost to Make Arrays Identical


class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans1 = 0, ans2 = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) ans1 += abs(arr[i] - brr[i]);
        ans2 += k;
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        for (int i = 0; i < n; i++) ans2 += abs(arr[i] - brr[i]);
        long long result = min(ans1, ans2);
        return result;
    }
};