class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) {
      return n;
    }

    // up: 最有一个差是正数的摆动序列
    // down: 最有一个差是负数的摆动序列
    vector<int> up(n), down(n);
    up[0] = down[0] = 1;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        down[i] = down[i - 1];
        up[i] = max(up[i - 1], down[i - 1] + 1);
      } else if (nums[i] < nums[i - 1]) {
        up[i] = up[i - 1];
        down[i] = max(down[i - 1], up[i - 1] + 1);
      } else {
        up[i] = up[i - 1];
        down[i] = down[i - 1];
      }
    }

    return max(up[n - 1], down[n - 1]);
  }
};