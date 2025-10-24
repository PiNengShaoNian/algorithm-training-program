class Solution {
 public:
  bool isBalance(int x) {
    vector<int> count(10);
    while (x > 0) {
      count[x % 10]++;
      x /= 10;
    }
    for (int i = 0; i < 10; i++) {
      if (count[i] > 0 && count[i] != i) {
        return false;
      }
    }
    return true;
  }

  int nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1224444; ++i) {
      if (isBalance(i)) {
        return i;
      }
    }
    return -1;
  }
};