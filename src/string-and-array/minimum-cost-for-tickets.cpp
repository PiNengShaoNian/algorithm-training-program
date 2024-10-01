class Solution {
public:
    vector<int> memo;
    unordered_set<int> day_set;
    vector<int> costs;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memo = vector<int>(366, -1);
        this->costs = costs;
        for (int day : days) {
            day_set.insert(day);
        }

        return dp(1);
    }

    // dp(i)表示从第i天开始旅游计划，最小的花费
    int dp(int i) {
        if (i > 365) {
            return 0;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        int ans;
        if (day_set.count(i)) {
            ans = min(min(dp(i + 1) + costs[0], dp(i + 7) + costs[1]), dp(i + 30) + costs[2]);
        } else {
            ans = dp(i + 1);
        }
        memo[i] = ans;
        return ans;
    }
};