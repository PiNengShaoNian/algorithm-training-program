class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int row = board.size();
    int col = board[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (board[i][j] == 'X') {
          if (i > 0 && board[i - 1][j] == 'X') {
            continue;
          }
          if (j > 0 && board[i][j - 1] == 'X') {
            continue;
          }
          ans++;
        }
      }
    }
    return ans;
  }
};