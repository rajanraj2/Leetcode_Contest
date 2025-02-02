// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/
// 3443. Maximum Manhattan Distance After K Changes


class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0, dist = 0, count = 0;
        int x = 0, y = 0;
        vector<pair<int, int>> arr = {{0,1}, {-1, 0}, {0, -1}, {1, 0}};

        int iter = 0;
        for (char ch : s) {
            // cout << ch << " iteration : " << iter << endl;
            iter++;
            int ind = 3;
            if (ch == 'N') ind = 0;
            else if (ch == 'W') ind = 1;
            else if (ch == 'S') ind = 2;
            // cout << "ind : " << ind << endl;

            int curr = abs(x + arr[ind].first) + abs(y + arr[ind].second);
            // cout << curr << " and " << dist << endl;
            // cout << x << " x and y " << y << endl;
            if (curr > dist) {
                // cout << ind << endl;
                // cout << arr[ind].first << endl;
                x += arr[ind].first;
                y += arr[ind].second;
                dist = curr;
                result = max(result, dist);
                // cout << x << " : " << y << endl;
                // cout << "dist : " << dist << "\n" <<endl;
                continue;
            }

            
            // for (int i = 0; i < 4; i++) {
            if (count < k) {
                int i = (ind + 2) % 4;
                // if (i == ind) continue;
                int val = abs(x + arr[i].first) + abs(y + arr[i].second);
                if (val > dist) {
                    x += arr[i].first;
                    y += arr[i].second;
                    dist = val;
                    result = max(result, dist);
                    count++;
                    // cout << "Final : " << i << endl;
                }
            }
            else {
                x += arr[ind].first;
                y += arr[ind].second;
                dist = curr;
            }
            // }
            // cout << "distance : " << dist << endl;
            // cout << x << " " << y << "\n" << endl;
        }
        
        return result;
    }
};