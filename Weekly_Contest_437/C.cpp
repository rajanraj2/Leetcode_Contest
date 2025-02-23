// https://leetcode.com/problems/select-k-disjoint-special-substrings/
// 3458. Select K Disjoint Special Substrings


class Solution {
    public:
        bool maxSubstringLength(string s, int k) {
            unordered_map<char, int> mpp;
            for (char ch : s) mpp[ch]++;
            int count = 0, n = s.size(), l = 0;
    
            while (l < n) {
                int r = l;
                unordered_set<char> st;
    
                while (r < n && st.count(s[r]) == 0 && mpp[s[r]] == 1) {
                    st.insert(s[r]);
                    r++;
                }
    
                if (!st.empty() && st.size() < n) {
                    count++;
                    if (count >= k) return true;
                } 
                l = ++r;
            }
            return false;
    
            // bool same = false;
            // char last = '';
            // for (auto it : mpp) {
            //     if (it.first == last) same = true;
            //     if (!same) {
            //         if (st.count(it) == 0) count++;
            //         else count--;
            //         st.insert(it);
            //     }
            //     last = it;
            // }
    
            // if (count < k) return false;
            // return true;
        }
    };
    