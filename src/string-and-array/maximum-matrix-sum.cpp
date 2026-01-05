class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    long long total = 0;
    int neg_cnt = 0;
    int mn = INT_MAX;
    for (auto& row : matrix) {
      for (int x : row) {
        if (x < 0) {
          neg_cnt++;
          x = -x;
        }
        mn = min(mn, x);
        total += x;
      }
    }
    if (neg_cnt % 2) {
      total -= 2 * mn;
    }
    return total;
  }
};