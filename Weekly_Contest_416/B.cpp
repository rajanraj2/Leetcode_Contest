// Link - https://leetcode.com/contest/weekly-contest-416/problems/minimum-number-of-seconds-to-make-mountain-height-zero/description/
// Minimum Number of Seconds to Make Mountain Height Zero


class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long result = 0;
        int n = workerTimes.size();
        sort(workerTimes.begin(), workerTimes.end());
        vector<int> arr(n, 0);

        int rem = mountainHeight;
        // if (rem >= n) {
        //     for (int i = 0; i < n; i++) arr[i] = rem / n;
        // }
        // rem -= n * (rem / n);

        int i = 0;
        while (rem) {
            arr[i]++;
            long long a = (long long)(workerTimes[i] * arr[i] * (arr[i] + 1) / 2);
            i++;
            rem--;
            if (i == n) {
                i = 0;
                continue;
            }

            arr[i]++;   
            long long b = (long long)(workerTimes[i] * arr[i] * (arr[i] + 1) / 2);
            cout << a << " " << b << endl; 
            if (a <= b) {
                // result = max(result, a);
                arr[i]--;
                i--;
            }
            else {
                // result = max(result, b);
                arr[i - 1]--;
                i--;
            }
        }

        for (int i = 0; i < n; i++) {
            result = max(result, (long long)(workerTimes[i] * arr[i] * (arr[i] + 1) / 2));
        }

        return result;
    }
};