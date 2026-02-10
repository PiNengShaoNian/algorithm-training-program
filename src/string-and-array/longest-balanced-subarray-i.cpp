class Solution {
 public:
  int longestBalanced(vector<int>& nums) {
    int len = 0;
    for (int i = 0; i < nums.size(); i++) {
      unordered_map<int, int> odd;
      unordered_map<int, int> even;

      for (int j = i; j < nums.size(); j++) {
        auto& c = (nums[j] & 1) ? odd : even;
        c[nums[j]]++;

        if (odd.size() == even.size()) {
          len = max(len, j - i + 1);
        }
      }
    }
    return len;
  }
};