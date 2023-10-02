class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMin(n);
    leftMin[0] = INT_MAX;

    for (int i = 1; i < n; i++) {
      leftMin[i] = min(leftMin[i - 1], nums[i - 1]);
    }

    vector<int> rightMax(n);
    rightMax[n - 1] = INT_MIN;
    for (int i = n - 2; i >= 0; i--) {
      rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
    }

    for (int i = 1; i < n - 1; i++) {
      if (nums[i] > leftMin[i] && nums[i] < rightMax[i]) {
        return true;
      }
    }

    return false;
  }
};