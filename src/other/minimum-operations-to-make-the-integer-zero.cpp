class Solution {
 public:
  int makeTheIntegerZero(int num1, int num2) {
    for (long long k = 1; k <= num1 - num2 * k; k++) {
      if (k >= popcount((uint64_t)num1 - num2 * k)) {
        return k;
      }
    }
    return -1;
  }
};