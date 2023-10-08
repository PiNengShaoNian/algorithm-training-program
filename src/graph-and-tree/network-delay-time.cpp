class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> distTo(n + 1, INT_MAX);
    for (const auto& time : times) {
      int from = time[0];
      int to = time[1];
      int weight = time[2];
      graph[from].push_back({to, weight});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        minPQ;
    minPQ.push({0, k});
    distTo[k] = 0;
    unordered_set<int> visited;
    while (minPQ.size()) {
      auto [dis, cur] = minPQ.top();
      minPQ.pop();
      visited.insert(cur);

      for (auto [neighbor, weight] : graph[cur]) {
        if (visited.count(neighbor)) {
          continue;
        }
        if (dis + weight < distTo[neighbor]) {
          distTo[neighbor] = dis + weight;
          minPQ.push({dis + weight, neighbor});
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans = max(ans, distTo[i]);
    }

    return ans == INT_MAX ? -1 : ans;
  }
};