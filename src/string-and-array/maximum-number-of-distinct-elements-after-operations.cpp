class Solution {
 public:
  int maxDistinctElements(vector<int>& nums, int k) {
    ranges::sort(nums);
    int ans = 0;
    int pre = INT_MIN;
    for (int x : nums) {
      x = min(max(x - k, pre + 1), x + k);
      if (x > pre) {
        ans++;
        pre = x;
      }
    }
    return ans;
  }
};