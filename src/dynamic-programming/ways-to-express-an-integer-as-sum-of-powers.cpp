class Solution {
 public:
  int numberOfWays(int n, int x) {
    vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; pow(i, x) <= n; i++) {
      int v = pow(i, x);
      for (int s = n; s >= v; s--) {
        f[s] += f[s - v];
      }
    }
    return f[n] % 1'000'000'007;
  }
};