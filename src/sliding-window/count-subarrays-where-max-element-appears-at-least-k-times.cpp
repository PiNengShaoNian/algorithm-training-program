class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = ranges::max(nums);
    long long ans = 0;
    int cnt_mx = 0;
    int left = 0;
    for (int x : nums) {
      cnt_mx += x == mx;
      while (cnt_mx == k) {
        cnt_mx -= nums[left] == mx;
        left++;
      }
      ans += left;
    }
    return ans;
  }
};