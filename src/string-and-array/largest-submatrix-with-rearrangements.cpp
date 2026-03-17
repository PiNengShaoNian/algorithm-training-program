class Solution {
 public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    vector<int> heights(n);
    int ans = 0;

    for (auto& row : matrix) {
      for (int j = 0; j < n; j++) {
        int x = row[j];
        if (x == 0) {
          heights[j] = 0;
        } else {
          heights[j]++;
        }
      }

      auto hs = heights;
      ranges::sort(hs);
      for (int i = 0; i < n; i++) {
        ans = max(ans, hs[i] * (n - i));
      }
    }

    return ans;
  }
};