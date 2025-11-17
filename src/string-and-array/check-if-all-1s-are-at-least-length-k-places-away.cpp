class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    if (k == 0) {
      return true;
    }
    int prevOne = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) {
        if (prevOne != -1 && i - prevOne - 1 < k) {
          return false;
        }
        prevOne = i;
      }
    }

    return true;
  }
};