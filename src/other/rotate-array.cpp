class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    // 当前已完成交换的位置
    int count = 0;
    // 当前交换环的起始位置
    int start = 0;
    while (count < n) {
      int idx = start;
      int tmp = nums[idx];
      int first = true;
      while (idx != start || first) {
        first = false;
        int next_idx = ((idx + k) % n);
        int next_tmp = nums[next_idx];
        nums[next_idx] = tmp;
        idx = next_idx;
        tmp = next_tmp;
        count++;
      }
      start++;
    }
  }
};