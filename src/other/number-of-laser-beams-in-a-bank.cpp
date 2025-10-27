class Solution {
 public:
  int numberOfBeams(vector<string>& bank) {
    int ans = 0;
    int last_cnt = 0;
    int n = bank.size();
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (char c : bank[i]) {
        if (c == '1') {
          cnt++;
        }
      }
      if (cnt) {
        ans += cnt * last_cnt;
        last_cnt = cnt;
      }
    }
    return ans;
  }
};