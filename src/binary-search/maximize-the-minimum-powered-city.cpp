class Solution {
 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + stations[i];
    }

    vector<long long> power(n);
    long long mn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      power[i] = sum[min(n, i + r + 1)] - sum[max(0, i - r)];
      mn = min(mn, power[i]);
    }

    auto check = [&](long long low) -> bool {
      vector<long long> diff(n + 1);
      long long sum_d = 0, built = 0;
      for (int i = 0; i < n; i++) {
        sum_d += diff[i];
        long long m = low - (power[i] + sum_d);
        if (m <= 0) {
          continue;
        }
        built += m;
        if (built > k) {
          return false;
        }
        sum_d += m;
        diff[min(n, i + 2 * r + 1)] -= m;
      }
      return true;
    };

    long long left = mn + k / n;
    long long right = mn + k;
    long long ans = left;
    while (left <= right) {
      long long mid = left + (right - left) / 2;
      if (check(mid)) {
        left = mid + 1;
        ans = mid;
      } else {
        right = mid - 1;
      }
    }
    return ans;
  }
};