// https://leetcode.com/problems/find-the-largest-almost-missing-integer/
// 3471. Find the Largest Almost Missing Integer


class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size(), result = -1, maxi = -1;
            int first = nums.front(), last = nums.back();
            int fir = 0, las = 0;
            map<int, int> mpp;
    
            for (int it : nums) {
                if (it == first) fir++;
                if (it == last) las++;
                maxi = max(maxi, it);
                mpp[it]++;
            }
    
            if (k == n) return maxi;
            if (k == 1) {
                for (auto it = mpp.rbegin(); it != mpp.rend(); it++) {
                    if (it->second == 1) return it->first;
                }
            }
            if (fir > 1) first = -1;
            if (las > 1) last = -1;
            return max(first, last);
        }
    };
    
    
    // brute force
    
    // class Solution {
    // public:
    //     int largestInteger(vector<int>& nums, int k) {
    //         int n = nums.size(), result = -1;
    //         map<int, int> mpp;
    //         for (int i = 0; i <= n - k; i++) {
    //             set<int> st;
    //             for (int j = i; j < i + k; j++) st.insert(nums[j]);
    //             for (auto it = st.begin(); it != st.end(); it++) mpp[*it]++;
    //         }
    //         for (auto it = mpp.begin(); it != mpp.end(); it++) {
    //             if (it->second == 1) result = max(result, it->first);
    //         }
    //         return result;
    //     }
    // };