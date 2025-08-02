class Solution {
 public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    unordered_map<int, int> cnt;
    for (int i = 0; i < basket1.size(); i++) {
      cnt[basket1[i]]++;
      cnt[basket2[i]]--;
    }

    vector<int> a, b;
    int mn = INT_MAX;
    for (auto [x, c] : cnt) {
      if (c % 2 != 0) {
        return -1;
      }
      mn = min(mn, x);
      if (c > 0) {
        for (int i = 0; i < c / 2; i++) {
          a.push_back(x);
        }
      } else {
        for (int i = 0; i < -c / 2; i++) {
          b.push_back(x);
        }
      }
    }

    ranges::sort(a);
    ranges::sort(b, greater());

    long long ans = 0;
    for (int i = 0; i < a.size(); i++) {
      ans += min({a[i], b[i], mn * 2});
    }
    return ans;
  }
};