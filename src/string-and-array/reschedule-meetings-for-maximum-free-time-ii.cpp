class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();

    // 计算空位长度
    auto get = [&](int i) -> int {
      if (i == 0) {
        return startTime[0];
      }
      if (i == n) {
        return eventTime - endTime[n - 1];
      }
      return startTime[i] - endTime[i - 1];
    };

    // 有 n+1 个空位，计算前三大的空位在哪
    int a = 0, b = -1, c = -1;
    for (int i = 1; i <= n; i++) {
      int sz = get(i);
      if (sz > get(a)) {
        c = b;
        b = a;
        a = i;
      } else if (b < 0 || sz > get(b)) {
        c = b;
        b = i;
      } else if (c < 0 || sz > get(c)) {
        c = i;
      }
    }

    int ans = 0;
    // 枚举桌子
    for (int i = 0; i < n; i++) {
      int sz = endTime[i] - startTime[i];
      if (i != a && i + 1 != a && sz <= get(a) ||
          i != b && i + 1 != b && sz <= get(b) || sz <= get(c)) {  // 可以移出去
        ans = max(ans, get(i) + sz + get(i + 1));
      } else {
        ans = max(ans, get(i) + get(i + 1));
      }
    }
    return ans;
  }
};