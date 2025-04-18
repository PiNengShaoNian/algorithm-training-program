class Solution {
 public:
  using ll = long long;
  long long countBadPairs(vector<int>& nums) {
    unordered_map<int, int> mp;
    ll res = 0;
    for (int i = 0; i < nums.size(); i++) {
      res += i - mp[nums[i] - i];
      mp[nums[i] - i]++;
    }
    return res;
  }
};