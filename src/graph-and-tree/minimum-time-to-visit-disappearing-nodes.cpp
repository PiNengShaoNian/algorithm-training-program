class Solution {
 public:
  vector<int> minimumTime(int n, vector<vector<int>>& edges,
                          vector<int>& disappear) {
    vector<vector<pair<int, int>>> adj(n);
    for (const auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      int t = edge[2];
      adj[u].emplace_back(v, t);
      adj[v].emplace_back(u, t);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.emplace(0, 0);
    vector<int> ans(n, -1);
    ans[0] = 0;
    while (!pq.empty()) {
      auto [t, u] = pq.top();
      pq.pop();
      if (ans[u] != t) {
        continue;
      }
      for (const auto& [v, length] : adj[u]) {
        if (t + length < disappear[v] &&
            (ans[v] == -1 || t + length < ans[v])) {
          ans[v] = t + length;
          pq.emplace(t + length, v);
        }
      }
    }
    return ans;
  }
};