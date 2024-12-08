// https://leetcode.com/problems/minimum-time-to-break-locks-i/
// Minimum Time to Break Locks I


class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int result = 0;
        int 
    }
};


// class Solution {
// public:
//     int findMinimumTime(vector<int>& strength, int k) {
//         int x = 1;
//         int result = 0;
//         int n = strength.size();
//         vector<int> visited(n, 0);
//         sort(strength.begin(), strength.end());
//         int time = strength[0];
//         result += time;
//         x += k;
//         time = 1;
//         int energy = x;
//         visited[0] = 1;
//         int prev, last;
        
//         for (int i = 1; i < n; i++) {
//             if (visited[i] == 1) continue;

//             while (energy < strength[i]) {
//                 energy += x;
//                 time++;
//             }

//             prev = i;
//             last = i;
//             while (i < n && strength[i] <= energy) {
//                 if (visited[i] == 0) last = i;
//                 i++;
//             }
//             // if (i < n && strength[i] > energy) i--;
//             // if (i >= n) i = n - 1;

//             visited[last] = 1;
//             result += time;
//             cout << result << endl;
//             x += k;
//             time = 1;
//             energy = x;
            
//             // if (visited[prev - 1] == 0) i = prev - 1;
//             // else i = prev;

//             if (last == prev) i = prev;
//             else i = prev - 1;
//         }
//         return result;
//     }
// };

// while strength[0] < energy : energy++;
// for the first lock :
// time = strength[0];
// result += time
// after that x += k;
// time = 1;
// energy = x;


// while (energy < strength[i]) :
// - energy += x;
// - time++;

// while (strength[i] <= energy) :
// - i++;
// visited[i] = 1;
// result += time
// after that x += k;
// time = 1;
// energy = x;

// i = prev;