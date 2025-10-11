class Solution {
 public:
  long long maximumTotalDamage(vector<int>& power) {
    map<int, int> cnt;
    // 把伤害一样的咒语统一成一类
    for (int p : power) {
      cnt[p]++;
    }
    vector<pair<int, int>> vec;
    for (auto p : cnt) {
      vec.push_back(p);
    }

    long long mx = 0;
    int n = vec.size();
    // dp[i]表示在前[0:i]范围内选咒语能达到的最大伤害
    vector<long long> dp(n, 0);
    for (int i = 0, j = 0; i < n; i++) {
      while (j < i && vec[j].first < vec[i].first - 2) {
        mx = max(mx, (long long)dp[j]);
        j++;
      }

      dp[i] = mx + 1ll * vec[i].first * vec[i].second;
    }

    return *max_element(dp.begin(), dp.end());
  }
};