// Link - https://leetcode.com/contest/weekly-contest-415/problems/the-two-sneaky-numbers-of-digitville/
// The two sneaky numbers of Digitville


class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (st.find(nums[i]) == st.end()) st.insert(nums[i]);
            else result.push_back(nums[i]);
        }
        return result;
    }
};