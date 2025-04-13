// https://leetcode.com/problems/number-of-unique-xor-triplets-i/
// 3513. Number of Unique XOR Triplets I


class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int pos = 0;

        while ((1 << (pos + 1)) <= n) {
            pos++;
        }

        int result = 1 << (pos + 1);
        return result;

        
        // int result = n;
        // unordered_set<int> st(nums.begin(), nums.end());
        // vector<int> arr;
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         if (i == j) continue;
        //         int val = i ^ j;
        //         arr.push_back(val);
        //     }
        // }
        // for (int it : arr) {
        //     for (int i = 1; i <= n; i++) {
        //         int val = it ^ i;
        //         if (st.find(val) == st.end()) {
        //             st.insert(val);
        //             result++;
        //         }
        //     }
        // }
        // return result;
    }
};