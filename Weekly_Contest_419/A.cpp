// Link - https://leetcode.com/contest/weekly-contest-419/problems/find-x-sum-of-all-k-long-subarrays-i/
// Find X Sum of All K Long Subarrays I


class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int l = 0, r = k - 1;
        vector<int> result(n - k + 1);

        map<int, int> mpp;
        for (int i = 0; i <= r; i++) {
            mpp[nums[i]]++;
        }

        auto getXSum = [&](map<int, int>& mpp, int x) -> int {
            vector<pair<int, int>> freqList(mpp.begin(), mpp.end());
            
            sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });

            int count = 0;
            int ans = 0;
            for (auto it : freqList) {
                if (count == x) break;
                ans += it.first * it.second;
                count++;
            }
            return ans;
        };

        result[0] = getXSum(mpp, x);


        for (int i = 1; i <= n - k; i++) {
            mpp[nums[i - 1]]--;
            if (mpp[nums[i - 1]] == 0) mpp.erase(nums[i - 1]);
            mpp[nums[i + k - 1]]++;
            result[i] = getXSum(mpp, x);
        }

        return result;
    }
};