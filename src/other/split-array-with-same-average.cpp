class Solution {
 public:
  bool splitArraySameAverage(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return false;
    }
    int m = n / 2;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < n; i++) {
      nums[i] = n * nums[i] - sum;
    }

    unordered_set<int> left;
    for (int i = 1; i < (1 << m); i++) {
      int tot = 0;
      for (int j = 0; j < m; j++) {
        if (i & (1 << j)) {
          tot += nums[j];
        }
      }
      if (tot == 0) {
        return true;
      }
      left.insert(tot);
    }

    int rsum = accumulate(nums.begin() + m, nums.end(), 0);
    for (int i = 1; i < (1 << (n - m)); i++) {
      int tot = 0;
      for (int j = m; j < n; j++) {
        if (i & (1 << (j - m))) {
          tot += nums[j];
        }
      }

      if (tot == 0 || (rsum != tot && left.count(-tot))) {
        return true;
      }
    }

    return false;
  }
};