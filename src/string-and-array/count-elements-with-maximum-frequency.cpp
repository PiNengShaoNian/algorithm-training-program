class Solution {
 public:
  int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int a : nums) {
      count[a]++;
    }
    int maxf = 0;
    for (auto const& pair : count) {
      if (pair.second > maxf) {
        maxf = pair.second;
      }
    }
    int res = 0;
    for (auto const& pair : count) {
      if (pair.second == maxf) {
        res += maxf;
      }
    }
    return res;
  }
};