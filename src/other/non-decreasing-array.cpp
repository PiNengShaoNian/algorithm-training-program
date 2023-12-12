class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = nums[i];
      int y = nums[i + 1];
      if (x > y) {
        cnt++;
        if (cnt > 1) {
          return false;
        }

        if (i > 0 && y < nums[i - 1]) {
          nums[i + 1] = x;
        }
      }
    }
    return true;
  }
};