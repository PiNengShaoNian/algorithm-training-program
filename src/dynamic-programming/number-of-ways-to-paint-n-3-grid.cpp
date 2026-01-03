constexpr int MOD = 1'000'000'007;
unordered_map<int, int> memo;

int dfs(int i, int j, int pre_row, int cur_row) {
  if (i == 0) {
    return 1;
  }

  if (j == 3) {
    return dfs(i - 1, 0, cur_row, 0);
  }

  // 参数压缩到一个 int 中
  int key = (i << 14) | (j << 12) | (pre_row << 6) | cur_row;
  if (memo.contains(key)) {  // 之前计算过
    return memo[key];
  }

  int res = 0;
  for (int color = 0; color < 3; color++) {
    if (pre_row > 0 && color == (pre_row >> (j * 2) & 3) ||
        j > 0 && color == (cur_row >> ((j - 1) * 2) & 3)) {
      continue;
    }
    res = (res + dfs(i, j + 1, pre_row, cur_row | (color << (j * 2)))) % MOD;
  }
  memo[key] = res;
  return res;
}

class Solution {
 public:
  int numOfWays(int n) { return dfs(n, 0, 0, 0); }
};