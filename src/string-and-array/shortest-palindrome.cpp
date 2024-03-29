class Solution {
 public:
  string shortestPalindrome(string s) {
    int n = s.size();
    int base = 131, mod = 1000000007;
    int left = 0, right = 0, mul = 1;
    int best = -1;
    for (int i = 0; i < n; i++) {
      // 正序hash, 最高位在左边
      left = ((long long)left * base + s[i]) % mod;
      // 逆序hash, 最高位在右边
      right = (right + (long long)s[i] * mul) % mod;
      if (left == right) {
        best = i;
      }
      mul = ((long long)mul * base) % mod;
    }
    string add = (best == n - 1 ? "" : s.substr(best + 1, n));
    reverse(add.begin(), add.end());
    return add + s;
  }
};