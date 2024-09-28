// Link - https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/
// Maximize the Total Height of Unique Towers


class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end());
        int n = maximumHeight.size();
        long long prev = maximumHeight[n - 1];
        set<int> st;
        long long result = prev;
        st.insert(prev);
        for (int i = n - 2; i >= 0; i--) {
            prev--;
            prev = min((long long)maximumHeight[i], prev);
            while (st.find(prev) != st.end() && prev > 0)  {
                prev--;
            }
            if (prev <= 0) {
                result = -1;
                break;
            }
            result += prev;
            st.insert(prev);
        }
        return result;
    }
};