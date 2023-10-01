class Solution {
 public:
  string join(vector<string>& words, int l, int r, string& sep) {
    string ans;
    bool first = true;
    for (int i = l; i <= r; i++) {
      if (!first) {
        ans += sep;
      }
      first = false;
      ans += words[i];
    }

    return ans;
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int n = words.size();
    int idx = 0;
    vector<string> ans;
    while (idx < n) {
      int end = idx;
      int len = words[idx].size();
      while (
          end + 1 < n &&
          (words[end + 1].size() + len + (end + 1 - idx + 1 - 1) <= maxWidth)) {
        end++;
        len += words[end].size();
      }

      int wordCnt = end - idx + 1;
      int whiteCnt = maxWidth - len;
      bool last = (end == n - 1);

      if (last) {
        string sep = " ";
        string str = join(words, idx, end, sep);
        if (maxWidth > str.size()) {
          string pad(maxWidth - str.size(), ' ');
          str += pad;
        }
        ans.push_back(str);
      } else {
        if (wordCnt == 1) {
          string str = words[idx];
          if (str.size() < maxWidth) {
            string pad(maxWidth - str.size(), ' ');
            str += pad;
          }
          ans.push_back(str);
        } else if (whiteCnt % (wordCnt - 1) == 0) {
          string sep(whiteCnt / (wordCnt - 1), ' ');
          ans.push_back(join(words, idx, end, sep));
        } else {
          int sep1Cnt = whiteCnt % (wordCnt - 1);
          string sep1(whiteCnt / (wordCnt - 1) + 1, ' ');
          string str1 = join(words, idx, idx + sep1Cnt, sep1);
          string sep2(whiteCnt / (wordCnt - 1), ' ');
          string str2 = join(words, idx + sep1Cnt + 1, end, sep2);
          string str = str1 + sep2 + str2;
          ans.push_back(str);
        }
      }
      idx = end + 1;
    }

    return ans;
  }
};