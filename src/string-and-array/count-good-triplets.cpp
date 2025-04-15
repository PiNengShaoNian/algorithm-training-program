class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b &&
              abs(arr[i] - arr[k]) <= c) {
            ++cnt;
          }
        }
      }
    }
    return cnt;
  }
};

class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int ans = 0, n = arr.size();
    vector<int> sum(1001, 0);
    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        if (abs(arr[j] - arr[k]) <= b) {
          int lj = arr[j] - a, rj = arr[j] + a;
          int lk = arr[k] - c, rk = arr[k] + c;
          int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
          if (l <= r) {
            if (l == 0) {
              ans += sum[r];
            } else {
              ans += sum[r] - sum[l - 1];
            }
          }
        }
      }
      for (int k = arr[j]; k <= 1000; ++k) {
        ++sum[k];
      }
    }
    return ans;
  }
};