class Solution {
 public:
  int nextGreaterElement(int num) {
    string nums = to_string(num);
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
      int big = 1e9;
      int bigIdx = -1;
      for (int j = i + 1; j < n; j++) {
        if (nums[i] < nums[j] && nums[j] < big) {
          big = nums[j];
          bigIdx = j;
        }
      }

      if (bigIdx != -1) {
        char tmp = nums[i];
        nums[i] = big;
        nums[bigIdx] = tmp;
        sort(nums.begin() + i + 1, nums.end());
        long ans = stol(nums);
        return ans > INT_MAX ? -1 : ans;
      }
    }
    return -1;
  }
};