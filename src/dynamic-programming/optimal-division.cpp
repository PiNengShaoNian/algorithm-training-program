struct Node {
  double maxVal, minVal;
  string minStr, maxStr;
  Node() {
    this->minVal = 10000.0;
    this->maxVal = 0.0;
  }
};

class Solution {
 public:
  string optimalDivision(vector<int>& nums) {
    int n = nums.size();
    // dp[i][j]表示nums[i:j]范围内能除到的最大值maxVal和其对于的字符串maxStr
    // 和能除到的最小值minVal和其对于的字符串minStr
    vector<vector<Node>> dp(n, vector<Node>(n));

    for (int i = 0; i < n; i++) {
      dp[i][i].minVal = nums[i];
      dp[i][i].maxVal = nums[i];
      dp[i][i].minStr = to_string(nums[i]);
      dp[i][i].maxStr = to_string(nums[i]);
    }

    // 枚举长度
    for (int len = 2; len <= n; len++) {
      // 枚举起始边界
      for (int i = 0; i < n; i++) {
        int j = i + len - 1;
        if (j >= n) {
          break;
        }
        // 枚举分割点
        // [i, k] [k+1, j]
        for (int k = i; k < j; k++) {
          if (dp[i][j].maxVal < dp[i][k].maxVal / dp[k + 1][j].minVal) {
            dp[i][j].maxVal = dp[i][k].maxVal / dp[k + 1][j].minVal;
            if (k + 1 == j) {
              dp[i][j].maxStr = dp[i][k].maxStr + "/" + dp[k + 1][j].minStr;
            } else {
              dp[i][j].maxStr =
                  dp[i][k].maxStr + "/(" + dp[k + 1][j].minStr + ")";
            }
          }

          if (dp[i][j].minVal > dp[i][k].minVal / dp[k + 1][j].maxVal) {
            dp[i][j].minVal = dp[i][k].minVal / dp[k + 1][j].maxVal;
            if (k + 1 == j) {
              dp[i][j].minStr = dp[i][k].minStr + "/" + dp[k + 1][j].maxStr;
            } else {
              dp[i][j].minStr =
                  dp[i][k].minStr + "/(" + dp[k + 1][j].maxStr + ")";
            }
          }
        }
      }
    }

    return dp[0][n - 1].maxStr;
  }
};