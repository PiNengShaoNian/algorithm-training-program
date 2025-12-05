class Solution {
 public:
  int countPartitions(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int left = 0;
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      left += nums[i];
      int right = sum - left;
      if ((right - left) % 2 == 0) {
        ans++;
      }
    }
    return ans;
  }
};