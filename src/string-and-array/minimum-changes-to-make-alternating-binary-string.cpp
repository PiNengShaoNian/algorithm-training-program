class Solution {
 public:
  int minOperations(string s) {
    int flag = 1;
    int ans1 = 0;
    int ans2 = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') != flag) {
        ans1++;
      } else {
        ans2++;
      }
      flag ^= 1;
    }

    return min(ans1, ans2);
  }
};