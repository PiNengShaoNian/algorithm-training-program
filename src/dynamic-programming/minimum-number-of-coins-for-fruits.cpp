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