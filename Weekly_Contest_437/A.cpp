// https://leetcode.com/problems/find-special-substring-of-length-k/
// 3456. Find Special Substring of Length K


class Solution {
    public:
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            for (int i = 0; i <= n - k; i++) {
                bool flag = true;
                for (int j = i; j < i + k; j++) {
                    if (s[j] != s[i]) {
                        flag = false;
                        break;
                    }
                }
                if (i > 0 && s[i - 1] == s[i]) flag = false;
                if (i + k < n && s[i + k] == s[i]) flag = false;
                if (flag) return true;
            }
            return false;
    
            
            // if (s.size() < k) return false;
            // bool result = false;
            // int start = 0,
            // multiset<int> st;
            // for (int end = 0, end < s.size(); s++) {
            //     st.insert(s[end]);
            // }
            // if (st.size() == k) {
            //     if (end == s.size()) {
            //         return true;
            //     }
            //     else if (s[end] != *st.begin()) {
            //         return true;
            //     }
            // }
    
            // for (int i = end; i < s.size(); i++) {
                
            // }
        }
    };