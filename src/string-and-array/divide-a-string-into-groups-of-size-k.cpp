class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> res;  // 分组后的字符串
    int n = s.size();
    int curr = 0;  // 每个分组的起始下标
    // 拆分字符串
    while (curr < n) {
      res.push_back(s.substr(curr, k));
      curr += k;
    }
    // 尝试填充最后一组
    res.back() += string(k - res.back().length(), fill);
    return res;
  }
};