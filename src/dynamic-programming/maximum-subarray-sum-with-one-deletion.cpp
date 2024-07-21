class Solution {
 public:
  int maximumSum(vector<int>& arr) {
    int n = arr.size();
    // dp[i][j]表示再以arr[i]为结尾的子数组(删除元素之前)，删除元素个数为j个的情况下能获得的最大和
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    int ans = arr[0];
    for (int i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
      ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    return ans;
  }
};