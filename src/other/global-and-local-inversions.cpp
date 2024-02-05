class Solution {
 public:
  bool isIdealPermutation(vector<int>& nums) {
    // 一个局部倒置一定是一个全局倒置，因此只需要判断存不存在一个全局导致nums[i] > nums[j](其中i < j + 1)
    // 即可判断全局倒置和局部倒置是否相等
    int n = nums.size();
    int minSuff = nums[n - 1];
    for (int i = n - 3; i >= 0; i--) {
      if (nums[i] > minSuff) {
        return false;
      }
      minSuff = min(minSuff, nums[i + 1]);
    }
    return true;
  }
};