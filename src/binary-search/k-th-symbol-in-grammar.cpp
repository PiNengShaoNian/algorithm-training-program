class Solution {
 public:
  int kthGrammar(int n, int k) {
    int left = 1, right = 1 << (n - 1), mid;
    int cur = 0;
    while (left < right) {
      mid = (left + right) >> 1;
      //   0
      // 1   0
      //   1
      // 1   0
      if (k > mid) {
        cur = cur == 0 ? 1 : 0;
        left = mid + 1;
      } else {
        cur = cur == 0 ? 0 : 1;
        right = mid;
      }
    }
    return cur;
  }
};