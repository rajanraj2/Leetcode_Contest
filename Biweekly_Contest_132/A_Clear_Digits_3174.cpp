// Link - https://leetcode.com/contest/biweekly-contest-132/problems/clear-digits/description/
// Clear Digits

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        bool found = true;
        while (found) {
            found = false;
            for (int i = 0; i < n; ++i) {
                if (isdigit(s[i]) == true) {
                    for (int j = i - 1; j >= 0; --j) {
                        if (!isdigit(s[j])) {
                            s.erase(s.begin() + i);
                            s.erase(s.begin() + j);
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
        }
        return s;
    }
};