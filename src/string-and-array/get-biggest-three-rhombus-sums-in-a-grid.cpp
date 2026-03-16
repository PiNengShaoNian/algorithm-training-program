#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    set<int> sums;  // 自动去重并排序

    // 预处理对角线前缀和
    // d1[r][c] 表示从左上往右下的累加
    // d2[r][c] 表示从右上往左下的累加
    vector<vector<int>> d1(m + 2, vector<int>(n + 2, 0));
    vector<vector<int>> d2(m + 2, vector<int>(n + 2, 0));

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
        d2[i + 1][j + 1] = d2[i][j + 2] + grid[i][j];
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // k=0 的情况（面积为0的菱形）
        sums.insert(grid[i][j]);

        // 枚举半径 k
        for (int k = 1; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n;
             ++k) {
          // 利用预处理的前缀和快速计算四条边
          int top = i - k, bottom = i + k, left = j - k, right = j + k;

          int s1 = d2[i + 1][left + 1] - d2[top][j + 2];      // 左上边
          int s2 = d1[bottom + 1][j + 1] - d1[i][left];       // 左下边
          int s3 = d2[bottom + 1][j + 1] - d2[i][right + 2];  // 右下边
          int s4 = d1[i + 1][right + 1] - d1[top][j];         // 右上边

          // 四条边相加后，减去重复计算的四个顶点
          int totalSum = s1 + s2 + s3 + s4 - grid[top][j] - grid[bottom][j] -
                         grid[i][left] - grid[i][right];
          sums.insert(totalSum);
        }

        // 保持 set 大小，只留最大的几个（可选优化）
        while (sums.size() > 3) sums.erase(sums.begin());
      }
    }

    // 将结果转为降序向量
    vector<int> result(sums.rbegin(), sums.rend());
    return result;
  }
};