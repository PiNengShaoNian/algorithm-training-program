class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    // dp[c]表示以字符c结尾的字串并且出现在循环串中的最大长度
    // 考虑字符串xbcd
    // dp[d] = 3; 因为字串bcd是以d结尾出现在循环串中的最长字串
    vector<int> dp(26);
    // 记录长度
    int k = 0;
    for (int i = 0; i < p.length(); i++) {
      if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {  // 字符之差为1或-25
        k++;
      } else {
        k = 1;
      }
      // 字串bcd必定包含了类似于cd和d这种字串在这里取max只考虑最长的字串
      // 就能去掉这种重复的答案
      dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};