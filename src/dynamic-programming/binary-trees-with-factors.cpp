class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    // dp[i]表示以arr[i]为根的二叉树个数
    vector<long long> dp(n);
    long long res = 0, mod = 1e9 + 7;
    // 枚举根节点坐标
    for (int i = 0; i < n; i++) {
      dp[i] = 1;
      // 若根节点为i，则它的左右子节点下标一定小于i
      for (int left = 0, right = i - 1; left <= right; left++) {
        while (left <= right && (long long)arr[left] * arr[right] > arr[i]) {
          right--;
        }

        if (left <= right && (long long)arr[left] * arr[right] == arr[i]) {
          // 如果左右子节点不相同则可以通过调换位置将树的数量翻倍
          dp[i] = (dp[i] + dp[left] * dp[right] * (1 + (left != right))) % mod;
        }
      }

      res = (res + dp[i]) % mod;
    }
    return res;
  }
};