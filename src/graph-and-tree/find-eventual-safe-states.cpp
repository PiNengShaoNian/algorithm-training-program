class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    // color[i] = 0 未访问; = 1 不安全节点; = 2 安全节点;
    vector<int> color(n);

    function<bool(int)> safe = [&](int x) {
      if (color[x] > 0) {
        return color[x] == 2;
      }

      color[x] = 1;
      for (int y : graph[x]) {
        if (!safe(y)) {
          return false;
        }
      }
      // 所有路径都没有环的情况下在将color[x]置为2
      color[x] = 2;
      return true;
    };

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (safe(i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};