class Solution {
 public:
  int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
    int n = coins.size();
    vector<vector<int>> graph(n);
    vector<int> degree(n);
    for (const auto& edge : edges) {
      int a = edge[0];
      int b = edge[1];
      degree[a]++;
      degree[b]++;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int rest = n;

    {
      queue<int> q;
      for (int i = 0; i < n; i++) {
        if (degree[i] == 1 && !coins[i]) {
          q.push(i);
        }
      }

      while (q.size()) {
        int vertex = q.front();
        q.pop();
        degree[vertex]--;
        rest--;

        for (int neighbor : graph[vertex]) {
          degree[neighbor]--;
          if (!coins[neighbor] && degree[neighbor] == 1) {
            q.push(neighbor);
          }
        }
      }
    }

    {
      for (int _ = 0; _ < 2; _++) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
          if (degree[i] == 1) {
            q.push(i);
          }
        }
        while (q.size()) {
          int vertex = q.front();
          q.pop();
          degree[vertex]--;
          rest--;

          for (int neighbor : graph[vertex]) {
            --degree[neighbor];
          }
        }
      }
    }

    return rest == 0 ? 0 : (rest - 1) * 2;
  }
};