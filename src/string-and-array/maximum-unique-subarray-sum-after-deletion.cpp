class Solution {
 public:
  int maxSum(vector<int>& nums) {
    int seen[101] = {0};
    int ans = 0;
    int has_positive = false;
    for (int num : nums) {
      if (num > 0 && !seen[num]) {
        ans += num;
        seen[num] = 1;
        has_positive = true;
      }
    }

    if (has_positive) {
      return ans;
    }
    sort(nums.begin(), nums.end());
    return nums.back();
  }
};