class Solution {
 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    int n = s.size();
    int m = indices.size();

    vector<int> ops(m);
    iota(ops.begin(), ops.end(), 0);
    sort(ops.begin(), ops.end(),
         [&](int i, int j) { return indices[i] < indices[j]; });

    string ans;

    int pt = 0;
    for (int i = 0; i < n;) {
      while (pt < m && indices[ops[pt]] < i) {
        pt++;
      }
      bool succeed = false;
      while (pt < m && indices[ops[pt]] == i) {
        if (s.substr(i, sources[ops[pt]].size()) == sources[ops[pt]]) {
          succeed = true;
          break;
        }
        pt++;
      }
      if (succeed) {
        ans += targets[ops[pt]];
        i += sources[ops[pt]].size();
      } else {
        ans += s[i];
        i++;
      }
    }

    return ans;
  }
};