class Solution {
 public:
  int maxIncreasingSubarrays(vector<int>& nums) {
    int cnt = 1;
    int pre_cnt = 0;
    int n = nums.size();
    int ans = INT_MIN;
    for (int i = 1; i < n; i++) {
      if (nums[i] > nums[i - 1]) {
        cnt++;
      } else {
        pre_cnt = cnt;
        cnt = 1;
      }

      ans = max(ans, min(cnt, pre_cnt));
      ans = max(ans, cnt / 2);
    }

    return ans;
  }
};