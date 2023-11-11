class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    bool flipFlag = true;
    // 先遍历第一行，并用flag正反交替添加到答案列表
    for (int j = 0; j < n; j++) {
      vector<int> list = helper(mat, n, m, 0, j);
      // flag为true, 反向遍历
      if (flipFlag) {
        for (int k = list.size() - 1; k >= 0; k--) {
          ans.push_back(list[k]);
        }
      } else {  // flag为false，正向遍历
        for (int num : list) {
          ans.push_back(num);
        }
      }
      flipFlag = !flipFlag;
    }
    // 再遍历最后一列（注意最后一列的第一个元素在上面已经被遍历到了），并用flag正反交替添加到答案列表
    for (int i = 1; i < m; i++) {
      vector<int> list = helper(mat, n, m, i, n - 1);
      // flag为true，反向遍历
      if (flipFlag) {
        for (int k = list.size() - 1; k >= 0; k--) {
          ans.push_back(list[k]);
        }
      }
      // flag为false，正向遍历
      else {
        for (int num : list) {
          ans.push_back(num);
        }
      }
      // 反转flag
      flipFlag = !flipFlag;
    }
    return ans;
  }
  // 以(x, y)位置为起点，往左下角遍历形成list
  vector<int> helper(vector<vector<int>>& mat, int n, int m, int x, int y) {
    vector<int> ans;
    while (x >= 0 && x < m && y >= 0 && y < n) {
      ans.push_back(mat[x][y]);
      x++;
      y--;
    }
    return ans;
  }
};