class Solution {
 public:
  int maxDistToClosest(vector<int>& seats) {
    int res = 0;
    int l = 0;
    int n = seats.size();
    while (l < n && seats[l] == 0) {
      l++;
    }
    // 只有右边有人，那就坐在第零位
    res = max(res, l);
    while (l < n) {
      int r = l + 1;
      while (r < n && seats[r] == 0) {
        ++r;
      }
      if (r == n) {
        // 只有左边有人那就坐在第n位
        res = max(res, r - l - 1);
      } else {
        // 两边都有人那就坐在正中间
        res = max(res, (r - l) / 2);
      }
      l = r;
    }
    return res;
  }
};