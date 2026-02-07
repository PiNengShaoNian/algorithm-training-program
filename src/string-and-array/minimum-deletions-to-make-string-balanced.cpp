class Solution {
 public:
  int minimumDeletions(string s) {
    int leftb = 0;
    int righta = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        righta++;
      }
    }

    int res = righta;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        righta--;
      } else {
        leftb++;
      }
      res = min(res, righta + leftb);
    }
    return res;
  }
};