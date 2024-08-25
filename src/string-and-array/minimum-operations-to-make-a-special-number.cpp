class Solution {
 public:
  int minimumOperations(string num) {
    int n = num.size();
    bool find0 = false;
    bool find5 = false;
    // 从右往左遍历在尾部构成00,50,25,75
    for (int i = n - 1; i >= 0; i--) {
      if (num[i] == '5' || num[i] == '0') {
        if (find0) {
          return n - i - 2;
        }

        if (num[i] == '5') {
          find5 = true;
        } else {
          find0 = true;
        }
      } else if (num[i] == '2' || num[i] == '7') {
        if (find5) {
          return n - i - 2;
        }
      }
    }
    if (find0) {
      return n - 1;
    }
    return n;
  }
};