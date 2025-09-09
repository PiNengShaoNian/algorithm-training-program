class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    const int MOD = 1'000'000'007;
    vector<int> known(n + 1);
    known[1] = 1;
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
      if (i >= n - forget + 1) {
        ans += known[i];
      }
      for (int j = i + delay; j <= min(i + forget - 1, n); j++) {
        known[j] = (known[j] + known[i]) % MOD;
      }
    }

    return ans % MOD;
  }
};