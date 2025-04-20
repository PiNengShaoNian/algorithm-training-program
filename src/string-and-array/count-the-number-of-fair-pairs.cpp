class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    // lower - nums[i] <= nums[j] <= upper - nums[i]
    for (int j = 0; j < nums.size(); j++) {
      auto r = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]);
      auto l = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]);
      ans += r - l;
    }
    return ans;
  }
};

class Solution {
 public:
  long long countFairPairs(vector<int>& nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int left = nums.size(), right = nums.size();
    for (int j = 0; j < nums.size(); ++j) {
      while (right && nums[right - 1] > upper - nums[j]) {
        right--;
      }
      while (left && nums[left - 1] >= lower - nums[j]) {
        left--;
      }
      ans += min(right, j) - min(left, j);
    }
    return ans;
  }
};