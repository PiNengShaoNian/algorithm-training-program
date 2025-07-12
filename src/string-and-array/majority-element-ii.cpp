class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> cnt;

    for (auto& v : nums) {
      cnt[v]++;
    }
    for (auto& v : cnt) {
      if (v.second > n / 3) {
        ans.push_back(v.first);
      }
    }

    return ans;
  }
};