class Solution {
 public:
  int expressiveWords(string s, vector<string> &words) {
    int ans = 0;
    for (const string &word : words) {
      if (expand(word, s)) {
        ans++;
      }
    }

    return ans;
  }

 private:
  bool expand(const string &word, const string &s) {
    int idx1 = 0;
    int idx2 = 0;
    while (idx1 < word.size() && idx2 < s.size()) {
      if (word[idx1] != s[idx2]) {
        return false;
      }

      char ch = word[idx1];
      int cnt1 = 0;
      while (idx1 < word.size() && word[idx1] == ch) {
        idx1++;
        cnt1++;
      }

      int cnt2 = 0;
      while (idx2 < s.size() && s[idx2] == ch) {
        idx2++;
        cnt2++;
      }

      // 无法拓展到更小的字符
      if (cnt2 < cnt1) {
        return false;
      }

      // 无法拓展到次数小于3的字符
      if (cnt1 != cnt2 && cnt2 < 3) {
        return false;
      }
    }
    return idx1 == word.size() && idx2 == s.size();
  }
};