class Solution {
 public:
  int numSubmat(vector<vector<int>>& mat) {
    int n = mat[0].size();
    vector<int> heights(n);
    int ans = 0;

    for (auto& row : mat) {
      for (int j = 0; j < n; j++) {
        if (row[j] == 0) {
          heights[j] = 0;
        } else {
          heights[j]++;
        }
      }

      stack<tuple<int, int, int>> st;
      st.emplace(-1, 0, -1);
      for (int j = 0; j < n; j++) {
        int h = heights[j];
        while (get<2>(st.top()) >= h) {
          st.pop();
        }
        auto [left, f, _] = st.top();
        f += (j - left) * h;
        ans += f;
        st.emplace(j, f, h);
      }
    }
    return ans;
  }
};