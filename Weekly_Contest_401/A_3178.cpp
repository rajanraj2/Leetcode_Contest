// Link - https://leetcode.com/contest/weekly-contest-401/problems/find-the-child-who-has-the-ball-after-k-seconds/
// Find the Child Who Has the Ball After K Seconds

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfChild(int n, int k) {
        if (n == 1) return 1;
        int current = 0;
        int next = 1;
        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (current == 0) flag = true;
            if (current == n - 1) flag = false;
            if (flag == true) {
                current++;
            }
            else {
                current--;
            }
        }
        return current;
    }
};


// class Solution {
// public:
//     int numberOfChild(int n, int k) {
//         int pass = 2 * (n - 1);
//         int pos =  pass % k;
//         if (pos >= n - 1) {
//             int last = pos - (n - 1);
//             int result = n - 1 - last;
//             return result;
//         }
//         else {

//         }
//     }
// };