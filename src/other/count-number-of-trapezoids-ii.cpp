class Solution {
 public:
  int countTrapezoids(vector<vector<int>>& points) {
    // 经测试，哈希表套 map
    // 比哈希表套哈希表更快（分组后，每一组的数据量比较小，在小数据下 map
    // 比哈希表快）
    unordered_map<double, map<double, int>> cnt;  // 斜率 -> 截距 -> 个数
    unordered_map<int, map<double, int>> cnt2;    // 中点 -> 斜率 -> 个数

    int n = points.size();
    for (int i = 0; i < n; i++) {
      int x = points[i][0], y = points[i][1];
      for (int j = 0; j < i; j++) {
        int x2 = points[j][0], y2 = points[j][1];
        int dy = y - y2;
        int dx = x - x2;
        double k = dx ? 1.0 * dy / dx : DBL_MAX;
        double b = dx ? 1.0 * (y * dx - x * dy) / dx : x;
        cnt[k][b]++;  // 按照斜率和截距分组
        int mid = (x + x2 + 2000) << 16 |
                  (y + y2 + 2000);  // 把二维坐标压缩成一个 int
        cnt2[mid][k]++;             // 按照中点和斜率分组
      }
    }

    int ans = 0;
    for (auto& [_, m] : cnt) {
      int s = 0;
      for (auto& [_, c] : m) {
        ans += s * c;
        s += c;
      }
    }

    for (auto& [_, m] : cnt2) {
      int s = 0;
      for (auto& [_, c] : m) {
        ans -= s * c;  // 平行四边形会统计两次，减去多统计的一次
        s += c;
      }
    }

    return ans;
  }
};