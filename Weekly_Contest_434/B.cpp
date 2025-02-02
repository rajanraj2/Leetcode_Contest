// https://leetcode.com/problems/count-mentions-per-user/description/
// 3433. Count Mentions Per User


class Solution {
public:
    void helper(string &vec, vector<int> &result) {
        int n = vec.size();
        int i = 0, ind = 0;
        while (i < n) {
            if (vec[i] == ' ') {
                result[ind]++;
                ind = 0;
                i++;
                continue;
            }
            if (vec[i] == 'i' || vec[i] == 'd') i++;
            else {
                ind += stoi(string(1, vec[i]));
                i++;
            }
        }
        result[ind]++;
        return;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b) {
            if (stoi(a[1]) == stoi(b[1])) {
                if (a[0] == "0") return a < b;
                else return b < a;
            } 
            else return stoi(a[1]) < stoi(b[1]);
        });
        
        int n = numberOfUsers;
        int s = events.size();
        vector<int> result(n), vis(n, 1);
        vector<pair<int, int>> arr;
        
        int online = n;
        int offline = 0;
        int total = 0;
        for (int i = 0; i < s; i++) {
            if (events[i][0] == "OFFLINE") {
                int num = stoi(events[i][2]);
                arr.push_back({stoi(events[i][1]) + 60, num});
                vis[num] = 0;
                online--;
                continue;
            }
            int ts = stoi(events[i][1]);
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i].first == ts) {
                    vis[arr[i].second] = 1;
                    arr.erase(arr.begin() + i);
                    online++;
                }
            }
            if (events[i][2] == "ALL") {
                total++;
            }
            else if (events[i][2] == "HERE") {
                for (int i = 0; i < n; i++) {
                    if (vis[i]) {
                        result[i]++;
                    }
                }
            }
            else {
                helper(events[i][2], result);
            }
        }

        for (int i = 0; i < n; i++) {
            result[i] += total;
        }
        return result;
    }
};