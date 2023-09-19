class Solution {
 public:
  int minCapability(vector<int>& nums, int k) {
    int l = *min_element(nums.begin(), nums.end());
    int r = *max_element(nums.begin(), nums.end());
    int ans = l;

    while (l <= r) {
      int mid = l + ((r - l) >> 1);

      int visited = false;
      int count = 0;
      for (int num : nums) {
        if (mid >= num && !visited) {
          visited = true;
          count++;
        } else {
          visited = false;
        }
      }

      if (count >= k) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }
};