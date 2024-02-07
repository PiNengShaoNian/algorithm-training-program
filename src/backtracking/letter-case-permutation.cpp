class Solution {
 private:
  void dfs(string &s, int idx, vector<string> &ans) {
    while (idx < s.size() && isdigit(s[idx])) {
      idx++;
    }
    if (idx == s.size()) {
      ans.push_back(s);
      return;
    }
    s[idx] ^= 32;
    dfs(s, idx + 1, ans);
    s[idx] ^= 32;
    dfs(s, idx + 1, ans);
  }

 public:
  vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    dfs(s, 0, ans);
    return ans;
  }
};