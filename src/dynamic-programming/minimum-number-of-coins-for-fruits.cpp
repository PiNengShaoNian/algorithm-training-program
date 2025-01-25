class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        // memo[i]表示购买(不过是真购买还是赠送)i及其后面的所有的水果需要的最少金币
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int index) -> int {
            if (2 * index + 2 >= prices.size()) {
                return prices[index];
            }
            if (!memo.count(index)) {
                int minValue = INT_MAX;
                for (int i = index + 1; i <= 2 * index + 2; i++) {
                    minValue = min(minValue, dp(i));
                }
                memo[index] = prices[index] + minValue;
            }
            return memo[index];
        };

        return dp(0);
    }
};

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<pair<int, int>> queue;
        queue.push_front({n, 0});
        for (int i = n - 1; i >= 0; i--) {
            while (!queue.empty() && queue.back().first >= 2 * i + 3) {
                queue.pop_back();
            }
            int cur = queue.back().second + prices[i];
            while (!queue.empty() && queue.front().second >= cur) {
                queue.pop_front();
            }
            queue.push_front({i, cur});
        }
        return queue.front().second;
    }
};