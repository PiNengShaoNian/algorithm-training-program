class Solution {
 public:
  string findLongestWord(string s, vector<string>& dictionary) {
    int m = s.size();
    // dp[i][j]表示s[i:m-1]范围内出现字符j的第一个位置
    vector<vector<int>> f(m + 1, vector<int>(26, m));

    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        if (s[i] == 'a' + j) {
          f[i][j] = i;
        } else {
          f[i][j] = f[i + 1][j];
        }
      }
    }

    string ans = "";
    for (string& t : dictionary) {
      bool match = true;
      int j = 0;
      for (int i = 0; i < t.size(); i++) {
        if (f[j][t[i] - 'a'] == m) {
          match = false;
          break;
        }
        j = f[j][t[i] - 'a'] + 1;
      }
      if (match) {
        if (t.size() > ans.size() || (t.size() == ans.size() && t < ans)) {
          ans = t;
        }
      }
    }
    return ans;
  }
};