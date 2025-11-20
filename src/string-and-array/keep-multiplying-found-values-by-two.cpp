class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    unordered_set<int> nums_set(nums.begin(), nums.end());

    while (nums_set.contains(original)) {
      original *= 2;
    }

    return original;
  }
};

class Solution {
 public:
  int findFinalValue(vector<int>& nums, int original) {
    sort(nums.begin(), nums.end());
    for (int num : nums) {
      if (original == num) {
        original *= 2;
      }
    }
    return original;
  }
};