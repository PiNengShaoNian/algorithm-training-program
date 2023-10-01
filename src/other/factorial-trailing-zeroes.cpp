class Solution {
 public:
  int trailingZeroes(int n) {
    // 实际上就是计算1-n之中有多少个5的因数。
    int ans = 0;
    for (int i = 5; i <= n; i += 5) {
      for (int x = i; x % 5 == 0; x /= 5) {
        ans++;
      }
    }

    return ans;
  }
};