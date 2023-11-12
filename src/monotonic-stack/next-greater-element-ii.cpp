class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    vector<int> stk;
    for (int i = 0; i < (2 * n); i++) {
      while (stk.size() && nums[i % n] > nums[stk.back()]) {
        ans[stk.back()] = nums[i % n];
        stk.pop_back();
      }
      stk.push_back(i % n);
    }
    return ans;
  }
};