const int MOD = 1'000'000'007;
const int MX = 100'000;

int pow2[MX];  // 2^i

auto init = [] {
  pow2[0] = 1;
  for (int i = 1; i < MX; i++) {
    pow2[i] = pow2[i - 1] * 2 % MOD;
  }
  return 0;
}();

class Solution {
 public:
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    long long ans = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] + nums[right] <= target) {
        ans += pow2[right - left];
        left++;
      } else {
        right--;
      }
    }
    return ans % MOD;
  }
};