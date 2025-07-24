class Solution {
 public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> g(n);
    for (auto& e : edges) {
      int x = e[0];
      int y = e[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    vector<int> xr(n), in(n), out(n);
    int clock = 0;
    auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
      in[x] = ++clock;
      xr[x] = nums[x];
      for (int y : g[x]) {
        if (y != fa) {
          dfs(y, x);
          xr[x] ^= xr[y];
        }
      }
      out[x] = clock;
    };

    dfs(0, -1);

    auto is_ancestor = [&](int x, int y) -> bool {
      return in[x] < in[y] && in[y] <= out[x];
    };

    int ans = INT_MAX;
    for (int x = 2; x < n; x++) {
      for (int y = 1; y < x; y++) {
        int a, b, c;
        if (is_ancestor(x, y)) {  // x 是 y 的祖先
          a = xr[y], b = xr[x] ^ a, c = xr[0] ^ xr[x];
        } else if (is_ancestor(y, x)) {  // y 是 x 的祖先
          a = xr[x], b = xr[y] ^ a, c = xr[0] ^ xr[y];
        } else {  // x 和 y 分别属于两棵不相交的子树
          a = xr[x], b = xr[y], c = xr[0] ^ a ^ b;
        }
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
        if (ans == 0) {
          return 0;
        }
      }
    }
    return ans;
  }
};