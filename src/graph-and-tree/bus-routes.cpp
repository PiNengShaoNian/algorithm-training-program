class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    int n = routes.size();
    unordered_map<int, vector<int>> siteToBuses;
    // 将每个bus设置为图中的一个点,
    // 如果两个bus直接会经过相同的站则它们直接存在边
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int site : routes[i]) {
        for (int j : siteToBuses[site]) {
          graph[i][j] = graph[j][i] = true;
        }
        siteToBuses[site].push_back(i);
      }
    }

    vector<int> dis(n, -1);
    queue<int> que;

    // 将所有包含起点站的bus加入队列
    for (int bus : siteToBuses[source]) {
      dis[bus] = 1;
      que.push(bus);
    }

    while (que.size()) {
      int x = que.front();
      que.pop();

      for (int y = 0; y < n; y++) {
        if (graph[x][y] && dis[y] == -1) {
          dis[y] = dis[x] + 1;
          que.push(y);
        }
      }
    }

    int ans = INT_MAX;

    for (int bus : siteToBuses[target]) {
      if (dis[bus] != -1) {
        ans = min(dis[bus], ans);
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};