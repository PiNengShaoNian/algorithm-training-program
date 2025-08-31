class Solution {
 public:
  vector<vector<char>>* board = nullptr;
  vector<vector<bool>> rows;
  vector<vector<bool>> cols;
  vector<vector<bool>> blocks;
  pair<int, int> findLeastPossibleLocation() {
    pair<int, int> ans = {-1, -1};
    int minCount = INT_MAX;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if ((*board)[i][j] != '.') {
          continue;
        }
        int count = 0;
        int blockId = i / 3 * 3 + j / 3;
        for (int k = 1; k <= 9; k++) {
          if (rows[i][k] && cols[j][k] && blocks[blockId][k]) {
            count++;
          }
        }
        if (count < minCount) {
          ans = {i, j};
          minCount = count;
        }
      }
    }

    return ans;
  }

  bool dfs() {
    auto [i, j] = findLeastPossibleLocation();

    if (i == -1) {
      return true;
    }

    int blockId = i / 3 * 3 + j / 3;
    for (int k = 1; k <= 9; k++) {
      if (!rows[i][k] || !cols[j][k] || !blocks[blockId][k]) {
        continue;
      }

      rows[i][k] = cols[j][k] = blocks[blockId][k] = false;
      (*board)[i][j] = (char)(k + '0');
      if (dfs()) {
        return true;
      }
      (*board)[i][j] = '.';
      rows[i][k] = cols[j][k] = blocks[blockId][k] = true;
    }

    return false;
  }

  void solveSudoku(vector<vector<char>>& board) {
    this->board = &board;
    rows = vector(9, vector(10, true));
    cols = vector(9, vector(10, true));
    blocks = vector(9, vector(10, true));

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] != '.') {
          int num = board[i][j] - '0';
          int blockId = i / 3 * 3 + j / 3;
          rows[i][num] = cols[j][num] = blocks[blockId][num] = false;
        }
      }
    }

    dfs();
  }
};