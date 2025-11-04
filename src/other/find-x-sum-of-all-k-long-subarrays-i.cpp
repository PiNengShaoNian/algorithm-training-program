class Solution {
 public:
  vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();
    vector<int> ans(n - k + 1);
    for (int i = 0; i <= n - k; ++i) {
      pair<int, int> cnt[51] = {};
      for (int j = i; j < i + k; ++j) {
        ++cnt[nums[j]].first;
        cnt[nums[j]].second = nums[j];
      }
      ranges::nth_element(cnt, cnt + x, greater{});
      ans[i] = transform_reduce(cnt, cnt + x, 0, plus{},
                                [](auto& p) { return p.first * p.second; });
    }
    return ans;
  }
};