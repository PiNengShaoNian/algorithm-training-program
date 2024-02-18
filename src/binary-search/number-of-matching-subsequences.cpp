class Solution {
 public:
  int numMatchingSubseq(string s, vector<string> &words) {
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); i++) {
      pos[s[i] - 'a'].push_back(i);
    }

    int ans = words.size();
    for (auto &w : words) {
      if (w.size() > s.size()) {
        ans--;
        continue;
      }

      // word的当前字符c能在s中最靠前的位置
      int p = -1;
      for (char c : w) {
        auto &ps = pos[c - 'a'];
        auto it = upper_bound(ps.begin(), ps.end(), p);
        if (it == ps.end()) {
          ans--;
          break;
        }
        p = *it;
      }
    }

    return ans;
  }
};