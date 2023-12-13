class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans;
    // 前n-k个数字产生的差都是1
    for (int i = 1; i < n - k; i++) {
      ans.push_back(i);
    }

    // 后k个数字产生的差各不相同
    for (int i = n - k, j = n; i <= j; i++, j--) {
      ans.push_back(i);
      if (i != j) {
        ans.push_back(j);
      }
    }
    return ans;
  }
};