class Solution {
  // 返回 [1,n] 的单个元素的操作次数之和
  long long f(int n) {
    int m = bit_width((uint32_t)n);
    long long res = 0;
    for (int i = 1; i < m; i++) {
      res += 1LL * (i + 1) / 2 << (i - 1);
    }
    return res + 1LL * (m + 1) / 2 * (n + 1 - (1 << m >> 1));
  }

 public:
  long long minOperations(vector<vector<int>>& queries) {
    long long ans = 0;
    for (auto& q : queries) {
      ans += (f(q[1]) - f(q[0] - 1) + 1) / 2;
    }
    return ans;
  }
};