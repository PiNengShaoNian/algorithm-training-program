class Solution {
 public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y,
                                       int k) {
    for (int col = y; col < y + k; col++) {
      int top = x;
      int bottom = x + k - 1;
      while (top < bottom) {
        int temp = grid[top][col];
        grid[top][col] = grid[bottom][col];
        grid[bottom][col] = temp;
        top++;
        bottom--;
      }
    }

    return grid;
  }
};