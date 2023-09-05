class Solution {
 public:
  // 检验times个abs(x)相加是否小于等于abs(target), 其中target和x都为负数
  int quickAdd(int target, int x, int times) {
    int add = x;
    int result = 0;

    while (times) {
      if (times & 1) {
        // 保证 result + add >= target
        if (result < target - add) {
          return false;
        }

        result += add;
      }

      if (times != 1) {
        // 保证 add + add >= target
        if (add < target - add) {
          return false;
        }
        add += add;
      }

      times >>= 1;
    }

    return true;
  }

  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN) {
      if (divisor == 1) {
        return INT_MIN;
      }
    }

    if (dividend == 0) {
      return 0;
    }

    // 将被除数和除数统一翻转为负数，方便计算
    int l = 1;
    int r = INT_MAX;
    int ans = 0;
    bool rev = false;
    if (dividend > 0) {
      dividend = -dividend;
      rev = !rev;
    }
    if (divisor > 0) {
      divisor = -divisor;
      rev = !rev;
    }

    while (l <= r) {
      int mid = l + ((r - l) >> 1);

      if (quickAdd(dividend, divisor, mid)) {
        ans = mid;
        if (mid == INT_MAX) {
          break;
        }
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return rev ? -ans : ans;
  }
};