class Solution {
 public:
  vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens,
                                          vector<int>& king) {
    int board[8][8];
    memset(board, 0, sizeof(board));

    for (vector<int>& q : queens) {
      board[q[0]][q[1]] = 1;
    }

    vector<vector<int>> ans;
    vector<pair<int, int>> directions = {{1, 0},   {-1, 0}, {0, -1}, {0, 1},
                                         {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++) {
      int x = king[0];
      int y = king[1];
      int dx = directions[i].first;
      int dy = directions[i].second;

      for (int nx = x + dx, ny = y + dy;; nx += dx, ny += dy) {
        if (nx >= 8 || nx < 0 || ny >= 8 || ny < 0) {
          break;
        }

        if (board[nx][ny]) {
          ans.emplace_back(vector<int>{nx, ny});
          break;
        }
      }
    }

    return ans;
  }
};