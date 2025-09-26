class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int left = j + 1;
        int right = n - 1;
        int k = j;
        while (left <= right) {
          int mid = (left + right) / 2;
          if (nums[mid] < nums[i] + nums[j]) {
            k = mid;
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
        ans += k - j;
      }
    }
    return ans;
  }
};