class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int l = j + 1;
        int r = n - 1;
        int k = j;
        while (l <= r) {
          int mid = l + ((r - l) >> 1);
          if (nums[i] + nums[j] > nums[mid]) {
            k = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }

        ans += k - j;
      }
    }
    return ans;
  }

  int triangleNumber1(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = i + 1; j < n; j++) {
        while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
          k++;
        }
        ans += max(k - j, 0);
      }
    }

    return ans;
  }
};