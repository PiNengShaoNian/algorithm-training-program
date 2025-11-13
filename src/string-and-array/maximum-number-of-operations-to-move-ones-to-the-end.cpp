class Solution {
 public:
  int maxOperations(string s) {
    int ans = 0;
    int cnt1 = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        cnt1++;
      } else if (i > 0 && s[i - 1] == '1') {
        ans += cnt1;
      }
    }
    return ans;
  }
};