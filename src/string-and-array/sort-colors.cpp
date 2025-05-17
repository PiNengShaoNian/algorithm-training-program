class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int n = nums.size();
    int ptr = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        swap(nums[ptr++], nums[i]);
      }
    }

    for (int i = ptr; i < n; i++) {
      if (nums[i] == 1) {
        swap(nums[ptr++], nums[i]);
      }
    }
  }
};