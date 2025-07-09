class Solution {
 public:
  int maxValue(vector<vector<int>> &events, int k) {
    if (k == 1) {
      return ranges::max(events, {}, [](auto &e) { return e[2]; })[2];
    }

    ranges::sort(events, {}, [](auto &e) { return e[1]; });
    int n = events.size();
    vector f(n + 1, vector<int>(k + 1));
    for (int i = 0; i < n; i++) {
      int p = lower_bound(events.begin(), events.begin() + i, events[i][0],
                          [](auto &e, int lower) { return e[1] < lower; }) -
              events.begin();

      for (int j = 1; j <= k; j++) {
        f[i + 1][j] = max(f[i][j], f[p][j - 1] + events[i][2]);
      }
    }
    return f[n][k];
  }
};