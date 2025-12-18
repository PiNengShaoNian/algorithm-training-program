class Solution {
 public:
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int n = prices.size();
    vector<long long> priceSum(n + 1);
    vector<long long> profitSum(n + 1);

    for (int i = 0; i < n; i++) {
      profitSum[i + 1] = profitSum[i] + strategy[i] * prices[i];
      priceSum[i + 1] = priceSum[i] + prices[i];
    }

    long long res = profitSum[n];
    for (int i = k - 1; i < n; i++) {
      long long leftProfile = profitSum[i - k + 1];
      long long changeProfile = priceSum[i + 1] - priceSum[i - k / 2 + 1];
      long long rightProfile = profitSum[n] - profitSum[i + 1];
      res = max(res, leftProfile + changeProfile + rightProfile);
    }
    return res;
  }
};