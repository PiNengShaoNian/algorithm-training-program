class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto&& edge : edges) {
      indeg[edge[1]]++;
      g[edge[0]].push_back(edge[1]);
    }

    int found = 0;
    vector<array<int, 26>> f(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
      if (!indeg[i]) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      ++found;
      int u = q.front();
      q.pop();
      f[u][colors[u] - 'a']++;
      for (int v : g[u]) {
        indeg[v]--;
        for (int c = 0; c < 26; c++) {
          f[v][c] = max(f[v][c], f[u][c]);
        }
        if (!indeg[v]) {
          q.push(v);
        }
      }
    }

    if (found != n) {
      return -1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, *max_element(f[i].begin(), f[i].end()));
    }
    return ans;
  }
};