class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    int rows[10][10] = {0};
    int cols[10][10] = {0};
    int blocks[10][10] = {0};
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          continue;
        }
        int num = board[i][j] - '0';
        if (rows[i][num]) {
          return false;
        }
        rows[i][num] = 1;
        if (cols[j][num]) {
          return false;
        }
        cols[j][num] = 1;
        if (blocks[i / 3 * 3 + j / 3][num]) {
          return false;
        }
        blocks[i / 3 * 3 + j / 3][num] = 1;
      }
    }
    return true;
  }
};