class Solution {
 public:
  int minimizeMax(vector<int>& nums, int p) {
    sort(nums.begin(), nums.end());
    auto check = [&](int mx) -> bool {
      int cnt = 0;
      for (int i = 0; i < nums.size() - 1; i++) {
        if (nums[i + 1] - nums[i] <= mx) {
          i++;
          cnt++;
        }
      }
      return cnt >= p;
    };

    int left = 0;
    int right = nums.back() - nums[0];
    int ans = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (check(mid)) {
        ans = mid;
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};