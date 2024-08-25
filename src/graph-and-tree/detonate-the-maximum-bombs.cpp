class Solution {
 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    function<bool(int, int)> isConnected = [&bombs](int u, int v) -> bool {
      long long dx = bombs[u][0] - bombs[v][0];
      long long dy = bombs[u][1] - bombs[v][1];
      return (long long)bombs[u][2] * bombs[u][2] >= dx * dx + dy * dy;
    };

    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i != j && isConnected(i, j)) {
          adj[i].push_back(j);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      queue<int> q;
      q.push(i);
      vector<int> visited(n);
      visited[i] = 1;
      int cnt = 1;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int neighbor : adj[cur]) {
          if (!visited[neighbor]) {
            visited[neighbor] = 1;
            cnt++;
            q.push(neighbor);
          }
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};