class Solution {
 public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    // x | x + 1相当于将x的二进制中最最右边的0变成1
    for (int& x : nums) {
      int res = -1;
      int d = 1;
      while ((x & d) != 0) {
        res = x - d;
        d <<= 1;
      }
      x = res;
    }
    return nums;
  }
};