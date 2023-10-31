class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>> &points) {
    int ans = 0;
    // 枚举中间的拐点
    for (auto &p : points) {
      // cnt[x]代表到p点的距离为x的点的数量
      unordered_map<int, int> cnt;
      for (auto &q : points) {
        int dis = (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
        cnt[dis]++;
      }
      for (auto &[_, m] : cnt) {
        // 有m个点的距离到p的距离都一样，我们从中选出其中两个这种总共有m * (m - 1)种选法
        ans += m * (m - 1);
      }
    }
    return ans;
  }
};