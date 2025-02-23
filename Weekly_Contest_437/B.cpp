// https://leetcode.com/problems/eat-pizzas/
// 3457. Eat Pizzas!


class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            sort(pizzas.rbegin(), pizzas.rend());
            long long result = 0;
            int n = pizzas.size();
            int days = n / 4;
            int count = 0;
    
            for (int i = 0; i < n && count < days; i++) {
                result += pizzas[i];
                cout << pizzas[i] << endl;
                if (count % 2 == 0) i++;
                count++;
            }
            return result;
        }
    };