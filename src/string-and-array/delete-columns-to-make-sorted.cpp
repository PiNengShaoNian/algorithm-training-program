class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    int cols = strs[0].size();
    int rows = strs.size();
    for (int col = 0; col < cols; col++) {
      for (int row = 1; row < rows; row++) {
        if (strs[row][col] < strs[row - 1][col]) {
          ans++;
          break;
        }
      }
    }
    return ans;
  }
};