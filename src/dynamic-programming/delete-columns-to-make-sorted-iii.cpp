class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int n = strs[0].size();
    vector<int> dp(n, 1);

    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        bool valid = true;
        for (string& row : strs) {
          if (row[i] > row[j]) {
            valid = false;
            break;
          }
        }

        if (valid) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    return n - *max_element(dp.begin(), dp.end());
  }
};