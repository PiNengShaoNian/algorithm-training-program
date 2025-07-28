class Solution {
 public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    int maxValue = 0;
    int cnt = 0;
    int stateNumber = 1 << n;
    for (int i = 0; i < stateNumber; i++) {
      int cur = 0;
      for (int j = 0; j < n; j++) {
        if (((i >> j) & 1) == 1) {
          cur |= nums[j];
        }
      }
      if (cur == maxValue) {
        cnt++;
      } else if (cur > maxValue) {
        maxValue = cur;
        cnt = 1;
      }
    }
    return cnt;
  }
};