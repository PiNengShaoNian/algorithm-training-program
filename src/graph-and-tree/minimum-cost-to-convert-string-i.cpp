class Solution {
 private:
  static constexpr int inf = INT_MAX / 2;

 public:
  long long minimumCost(string source, string target, vector<char>& original,
                        vector<char>& changed, vector<int>& cost) {
    vector<vector<int>> G(26, vector<int>(26, inf));
    for (int i = 0; i < 26; i++) {
      G[i][i] = 0;
    }

    int m = original.size();
    for (int i = 0; i < m; i++) {
      int idx = original[i] - 'a';
      int idy = changed[i] - 'a';
      G[idx][idy] = min(G[idx][idy], cost[i]);
    }

    for (int k = 0; k < 26; k++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        }
      }
    }

    long long ans = 0;
    int n = source.size();
    for (int i = 0; i < n; i++) {
      int idx = source[i] - 'a';
      int idy = target[i] - 'a';
      if (G[idx][idy] == inf) {
        return -1;
      }
      ans += G[idx][idy];
    }
    return ans;
  }
};