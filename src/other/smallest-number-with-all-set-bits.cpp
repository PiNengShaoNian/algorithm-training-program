class Solution {
 public:
  int smallestNumber(int n) {
    for (int i = 1; i <= 31; i++) {
      if (((1 << i) - 1) >= n) {
        return (1 << i) - 1;
      }
    }
    return -1;
  }
};
