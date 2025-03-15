// https://leetcode.com/problems/unique-3-digit-even-numbers/
// 3483. Unique 3-Digit Even Numbers


class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            vector<int> arr(10, 0);
            for (auto it : digits) arr[it]++;
            unordered_set<int> st;
    
            for (int a = 1; a <= 9; a++) {
                for (int c = 0; c <= 8; c += 2) {
                    for (int b = 0; b <= 9; b++) {
                        if (a == b && b == c) {
                            if (arr[a] < 3) continue;
                        } 
                        else if (a == b) {
                            if (arr[a] < 2 || arr[c] < 1) continue;
                        } 
                        else if (b == c) {
                            if (arr[b] < 2 || arr[a] < 1) continue;
                        } 
                        else if (a == c) {
                            if (arr[a] < 2 || arr[b] < 1) continue;
                        } 
                        else {
                            if (arr[a] < 1 || arr[b] < 1 || arr[c] < 1) continue;
                        }
                        int val = 100 * a + 10 * b + c;
                        st.insert(val);
                    }
                }
            }
            return st.size();
        }
    };