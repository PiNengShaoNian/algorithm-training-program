class UnionFind {
  vector<int> f;
  int n;

 public:
  UnionFind(int n) : n(n) {
    f.resize(n);
    for (int i = 0; i < n; i++) {
      f[i] = i;
    }
  }

  int find(int x) {
    if (f[x] != x) {
      f[x] = find(f[x]);
    }
    return f[x];
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
      return;
    }

    if (x > y) {
      swap(x, y);
    }

    f[y] = x;
  }
};

class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    UnionFind uf(26);
    for (int i = 0; i < s1.size(); i++) {
      int x = s1[i] - 'a';
      int y = s2[i] - 'a';
      uf.unite(x, y);
    }
    for (int i = 0; i < baseStr.size(); i++) {
      baseStr[i] = 'a' + uf.find(baseStr[i] - 'a');
    }
    return baseStr;
  }
};