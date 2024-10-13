// Link - https://leetcode.com/contest/weekly-contest-419/problems/find-x-sum-of-all-k-long-subarrays-ii/
// Find X Sum of All K Long Subarrays II


class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = k - 1;
        vector<long long> result(n - k + 1);

        unordered_map<int, int> mpp;

        for (int i = 0; i <= r; i++) {
            mpp[nums[i]]++;
        }

        auto getXSum = [&]() -> long long {
            priority_queue<pair<int, int>> maxHeap;
            for (auto& [num, freq] : mpp) {
                maxHeap.push({freq, num});
            }

            long long ans = 0;
            for (int it = 0; it < x && !maxHeap.empty(); it++) {
                ans += (long long)maxHeap.top().first * maxHeap.top().second;
                maxHeap.pop();
            }
            return ans;
        };

        result[0] = getXSum();


        for (int i = 1; i <= n - k; i++) {
            int ot = nums[i - 1];
            int in  = nums[i + k - 1];

            mpp[ot]--;
            if (mpp[ot] == 0) mpp.erase(ot);
            mpp[in]++;

            result[i] = getXSum();
        }

        return result;
    }
};