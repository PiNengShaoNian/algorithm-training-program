class Solution {
  static constexpr int mod = 1000000007;

 public:
  int colorTheGrid(int m, int n) {
    unordered_map<int, vector<int>> valid;
    // 将每一行的涂色方案表示为一个m位的三进制数字
    int mask_end = pow(3, m);
    for (int mask = 0; mask < mask_end; mask++) {
      vector<int> color(m);
      int mm = mask;
      for (int i = 0; i < m; i++) {
        color[i] = mm % 3;
        mm /= 3;
      }
      bool check = true;
      for (int i = 0; i < m - 1; i++) {
        if (color[i] == color[i + 1]) {
          check = false;
          break;
        }
      }
      if (check) {
        valid[mask] = move(color);
      }
    }

    unordered_map<int, vector<int>> adj;
    for (const auto &[mask1, color1] : valid) {
      for (const auto &[mask2, color2] : valid) {
        bool check = true;
        for (int i = 0; i < m; i++) {
          if (color1[i] == color2[i]) {
            check = false;
            break;
          }
        }
        if (check) {
          adj[mask1].push_back(mask2);
        }
      }
    }

    // f[i][mask]表示当为前i行涂完颜色，切最后一行的涂色方案为mask时总共的涂色方案数
    vector<int> f(mask_end);
    for (const auto &[mask, _] : valid) {
      f[mask] = 1;
    }

    for (int i = 1; i < n; i++) {
      vector<int> g(mask_end);
      for (const auto &[mask2, _] : valid) {
        for (int mask1 : adj[mask2]) {
          g[mask2] = (g[mask2] + f[mask1]) % mod;
        }
      }
      f = move(g);
    }

    int ans = 0;
    for (int num : f) {
      ans = (ans + num) % mod;
    }
    return ans;
  }
};