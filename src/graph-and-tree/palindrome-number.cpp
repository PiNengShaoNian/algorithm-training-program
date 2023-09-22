class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
      revertedNumber *= 10;
      revertedNumber += x % 10;
      x /= 10;
    }

    return x == revertedNumber || revertedNumber / 10 == x;
  }
};