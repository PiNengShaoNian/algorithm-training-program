class Solution {
 public:
  int uniqueLetterString(string s) {
    // 存储一个字符在s中出现的所有位置
    unordered_map<char, vector<int>> index;
    for (int i = 0; i < s.size(); i++) {
      index[s[i]].emplace_back(i);
    }
    int ans = 0;
    for (auto &&[_, arr] : index) {
      arr.insert(arr.begin(), -1);
      arr.emplace_back(s.size());
      for (int i = 1; i < arr.size() - 1; i++) {
        // 一个字符能否贡献答案取决于它处于几个不存在重复自己的子字符串
        // 当前字符为s[i]时这样的字符串的个数为(arr[i] - arr[i - 1]) * (arr[i +
        // 1] - arr[i])
        ans += (arr[i] - arr[i - 1]) * (arr[i + 1] - arr[i]);
      }
    }
    return ans;
  }
};