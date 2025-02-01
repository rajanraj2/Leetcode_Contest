// https://leetcode.com/contest/biweekly-contest-149/problems/reschedule-meetings-for-maximum-free-time-i/
// Reschedule Meetings for Maximum Free Time I


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        map<int, int> mpp;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            mpp[startTime[i]] = endTime[i];
        }

        vector<int> arr;
        int prev = 0;
        for (auto it : mpp) {
            int diff = it.first - prev;
            prev = it.second;
            if (diff < 0) continue;
            arr.push_back(diff);
        }
        int diff = eventTime - prev;
        if (diff > 0) arr.push_back(diff);

        int sum = 0, result = 0;

        for (int i = 0; i < k + 1; i++) {
            if (i >= arr.size()) break;
            sum += arr[i];
        }
        result = sum;

        for (int i = k + 1; i < arr.size(); i++) {
            sum += arr[i] - arr[i - k - 1];
            result = max(result, sum);
        }
        return result;
    }
};©leetcode