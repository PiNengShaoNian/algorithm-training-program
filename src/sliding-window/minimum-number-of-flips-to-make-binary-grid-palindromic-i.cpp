class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int rowCnt = 0;
        int colCnt = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++) {
            for (int l = 0, r = cols - 1; l < r; l++, r--) {
                if (grid[i][l] ^ grid[i][r]) {
                    rowCnt++;
                }
            }
        }

        for (int i = 0; i < cols; i++) {
            for (int l = 0, r = rows - 1; l < r; l++, r--) {
                if (grid[l][i] ^ grid[r][i]) {
                    colCnt++;
                }
            }
        }

        return min(rowCnt, colCnt);
    }
};