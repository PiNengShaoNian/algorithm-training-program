class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    int n = s.size();
    int m = 0;
    // 由于字符串长度较小(最长只有12)，我们可以在这里直接计算字母的种类
    // 并且用一个位图表示字母的大小写选择情况
    for (auto c : s) {
      if (isalpha(c)) {
        m++;
      }
    }
    vector<string> ans;
    // 枚举所有选择情况
    for (int mask = 0; mask < (1 << m); mask++) {
      string str;
      int k = 0;
      for (int i = 0; i < n; i++) {
        // 如果该位为1，表示该字母选择大写，反之选择小写
        if (isalpha(s[i]) && (mask & (1 << k++))) {
          str.push_back(toupper(s[i]));
        } else {
          str.push_back(tolower(s[i]));
        }
      }
      ans.push_back(str);
    }
    return ans;
  }
};