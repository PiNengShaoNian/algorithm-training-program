class Solution {
 public:
  int minimumPairRemoval(vector<int>& nums) {
    int count = 0;

    while (nums.size() > 1) {
      bool isAscending = true;
      int minSum = std::numeric_limits<int>::max();
      int targetIndex = -1;

      for (int i = 0; i < nums.size() - 1; i++) {
        int sum = nums[i] + nums[i + 1];
        if (nums[i] > nums[i + 1]) {
          isAscending = false;
        }
        if (sum < minSum) {
          targetIndex = i;
          minSum = sum;
        }
      }

      if (isAscending) {
        break;
      }

      count++;
      nums[targetIndex] = minSum;
      nums.erase(nums.begin() + targetIndex + 1);
    }

    return count;
  }
};