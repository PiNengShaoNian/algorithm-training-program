class Solution {
 public:
  int countCompleteSubarrays(vector<int>& nums) {
    int r = -1;
    int n = nums.size();
    unordered_map<int, int> cnt;
    unordered_set<int> distinct(nums.begin(), nums.end());
    int distinct_count = distinct.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
      while (r + 1 < n && cnt.size() < distinct_count) {
        r++;
        cnt[nums[r]]++;
      }

      if (cnt.size() >= distinct_count) {
        ans += n - r;
      }

      cnt[nums[i]]--;
      if (cnt[nums[i]] == 0) {
        cnt.erase(nums[i]);
      }
    }

    return ans;
  }
};