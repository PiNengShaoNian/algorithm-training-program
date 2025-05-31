class Solution {
  pair<int, int> id2rc(int id, int n) {
    int r = (id - 1) / n, c = (id - 1) % n;
    if (r % 2 == 1) {
      c = n - 1 - c;
    }
    return {n - 1 - r, c};
  }

 public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> vis(n * n + 1);
    queue<pair<int, int>> q;
    q.emplace(1, 0);
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      for (int i = 1; i <= 6; i++) {
        int nxt = p.first + i;
        if (nxt > n * n) {
          break;
        }
        auto rc = id2rc(nxt, n);
        if (board[rc.first][rc.second] > 0) {
          nxt = board[rc.first][rc.second];
        }
        if (nxt == n * n) {
          return p.second + 1;
        }
        if (!vis[nxt]) {
          vis[nxt] = true;
          q.emplace(nxt, p.second + 1);
        }
      }
    }
    return -1;
  }
};