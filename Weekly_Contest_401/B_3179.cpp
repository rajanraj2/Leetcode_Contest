// Link - https://leetcode.com/contest/weekly-contest-401/problems/find-the-n-th-value-after-k-seconds/
// Find the N-th Value After K Seconds

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<long long> a(n, 1);
        long long mod = 1000000007;
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < n; j++) {
                a[j] = (a[j] + a[j - 1]) % mod; 
            }
        }
        return static_cast<int>(a[n - 1]);
        
    }
};