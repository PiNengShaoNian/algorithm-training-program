class Solution {
 public:
  string clearStars(string s) {
    vector<int> stacks[26];
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '*') {
        stacks[s[i] - 'a'].push_back(i);
        continue;
      }

      for (auto &st : stacks) {
        if (!st.empty()) {
          st.pop_back();
          break;
        }
      }
    }

    vector<int> idx;
    for (auto &st : stacks) {
      idx.insert(idx.end(), st.begin(), st.end());
    }
    ranges::sort(idx);

    string ans(idx.size(), 0);
    for (int i = 0; i < idx.size(); i++) {
      ans[i] = s[idx[i]];
    }
    return ans;
  }
};