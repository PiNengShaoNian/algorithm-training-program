class Solution {
 public:
  string makeFancyString(string s) {
    string ans;
    for (char ch : s) {
      int n = ans.size();
      if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch) {
        continue;
      }
      ans.push_back(ch);
    }
    return ans;
  }
};