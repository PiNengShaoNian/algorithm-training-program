class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    int n = nums.size();
    // 一个数组中所有数字第i位的汉明距离可以这样算:
    // 1. 在n个元素的数组中计算出第i位为1的数字个数为c
    // 2. 第i位为0的数字个数为n - c
    // 3. 则就第所有数字第i位的汉明距离为 c * (n - c)
    // 要计算汉明距离，则累计所有位的汉明距离即可

    // 枚举位数
    for (int i = 0; i < 30; i++) {
      // 统计第i位为1的数字的数量
      int c = 0;
      for (int val : nums) {
        c += (val >> i) & 1;
      }
      ans += c * (n - c);
    }
    return ans;
  }
};