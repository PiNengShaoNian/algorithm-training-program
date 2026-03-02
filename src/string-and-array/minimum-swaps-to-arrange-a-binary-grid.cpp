class Solution {
 public:
  int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> tail_zeros(n, n);
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= 0; j--) {
        if (grid[i][j]) {
          tail_zeros[i] = n - 1 - j;
          break;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int j = i;
      while (j < n && tail_zeros[j] < n - 1 - i) {
        j++;
      }
      if (j == n) {
        return -1;
      }
      ans += j - i;
      copy_backward(tail_zeros.begin() + i, tail_zeros.begin() + j,
                    tail_zeros.begin() + j + 1);
    }
    return ans;
  }
};