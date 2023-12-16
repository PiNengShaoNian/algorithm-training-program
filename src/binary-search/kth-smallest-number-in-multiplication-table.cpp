class Solution {
 public:
  int findKthNumber(int m, int n, int k) {
    int left = 1, right = m * n;
    int ans = 1;
    while (left <= right) {
      int x = left + (right - left) / 2;
      // 计算那些一行中所有数字都大于x的行，他们包含的数字的数量
      int count = x / n * n;

      // 计算那些一行中只有部分数字大于x的行，他们包含大于x的数字的数量
      for (int i = x / n + 1; i <= m; i++) {
        count += x / i;
      }

      if (count >= k) {
        right = x - 1;
        ans = x;
      } else {
        left = x + 1;
      }
    }
    return ans;
  }
};