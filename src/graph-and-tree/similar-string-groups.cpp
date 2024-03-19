class Solution {
 public:
  vector<int> f;
  int find(int x) {
    if (x == f[x]) {
      return x;
    } else {
      return (f[x] = find(f[x]));
    }
  }

  bool check(string &s1, string &s2, int m) {
    int diff = 0;
    for (int i = 0; i < m; i++) {
      if (s1[i] != s2[i]) {
        diff++;
        if (diff > 2) {
          return false;
        }
      }
    }
    return true;
  }

  int numSimilarGroups(vector<string> &strs) {
    int n = strs.size();
    int m = strs[0].size();

    f.resize(n);
    for (int i = 0; i < n; i++) {
      f[i] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int fi = find(i);
        int fj = find(j);
        if (fi == fj) {
          continue;
        }
        if (check(strs[i], strs[j], m)) {
          f[fi] = fj;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (f[i] == i) {
        ans++;
      }
    }
    return ans;
  }
};