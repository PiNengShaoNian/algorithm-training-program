class Solution {
 public:
  vector<string> getPos(string s) {
    vector<string> pos;
    // 不含前置零和0本身就是一种选择
    if (s[0] != '0' || s == "0") pos.push_back(s);
    // 枚举将一个数分割为整数和小数部分的位置
    for (int p = 1; p < s.size(); p++) {
      // 过滤掉0xx.xx和xx.xx0这种非法格式
      if ((p != 1 && s[0] == '0') || s.back() == '0') {
        continue;
      }
      pos.push_back(s.substr(0, p) + "." + s.substr(p));
    }
    return pos;
  }
  vector<string> ambiguousCoordinates(string s) {
    s = s.substr(1, s.size() - 2);
    vector<string> ans;

    // 枚举将一个数分割为两个数的位置
    for (int p = 1; p < s.size(); p++) {
      vector<string> l = getPos(s.substr(0, p));
      if (l.empty()) {
        continue;
      }
      vector<string> r = getPos(s.substr(p));
      if (r.empty()) {
        continue;
      }

      for (auto &n1 : l) {
        for (auto &n2 : r) {
          ans.push_back("(" + n1 + ", " + n2 + ")");
        }
      }
    }
    return ans;
  }
};