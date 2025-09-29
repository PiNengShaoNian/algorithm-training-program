class Solution {
 public:
  int minScoreTriangulation(vector<int>& v) {
    int n = v.size();
    vector memo(n, vector<int>(n, -1));  // -1 表示没有计算过

    // lambda 递归函数
    auto dfs = [&](this auto&& dfs, int i, int j) -> int {
      if (i + 1 == j) {
        return 0;  // 只有两个点，无法组成三角形
      }
      int& res = memo[i][j];  // 注意这里是引用，修改 res 相当于修改 memo[i][j]
      if (res != -1) {        // 之前计算过
        return res;
      }
      res = INT_MAX;
      for (int k = i + 1; k < j; k++) {  // 枚举顶点 k
        res = min(res, dfs(i, k) + dfs(k, j) + v[i] * v[j] * v[k]);
      }
      return res;
    };

    return dfs(0, n - 1);
  }
};