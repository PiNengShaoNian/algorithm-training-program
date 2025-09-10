class Solution {
 public:
  int minimumTeachings(int n, vector<vector<int>>& languages,
                       vector<vector<int>>& friendships) {
    int m = languages.size();
    vector learned(m, vector<int8_t>(n + 1));
    for (int i = 0; i < m; i++) {
      for (int x : languages[i]) {
        learned[i][x] = true;
      }
    }

    vector<pair<int, int>> todo_list;
    for (auto& f : friendships) {
      int u = f[0] - 1;
      int v = f[1] - 1;
      bool ok = false;
      for (int x : languages[u]) {
        if (learned[v][x]) {
          ok = true;
          break;
        }
      }

      if (!ok) {
        todo_list.emplace_back(u, v);
      }
    }

    int ans = m;
    for (int k = 1; k <= n; k++) {
      unordered_set<int> st;
      for (auto& [u, v] : todo_list) {
        if (!learned[u][k]) {
          st.insert(u);
        }
        if (!learned[v][k]) {
          st.insert(v);
        }
      }
      ans = min(ans, (int)st.size());
    }
    return ans;
  }
};