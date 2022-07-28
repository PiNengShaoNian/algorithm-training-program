//记忆化搜索
class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
    vector<vector<int>> memo;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 1;
        rows = matrix.size();
        cols = matrix[0].size();
        memo = vector<vector<int>>(rows, vector<int>(cols, -1));

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>> &matrix, int row, int col) {
        if(memo[row][col] != -1) return memo[row][col];

        int ans = 0;
        for(int i = 0; i < 4; ++i) {
            int new_row = row + dirs[i][0];
            int new_col = col + dirs[i][1];

            if(new_row >= 0 && new_row < rows 
            && new_col >= 0 && new_col < cols 
            && matrix[new_row][new_col] > matrix[row][col]) {
                ans = max(ans, dfs(matrix, new_row, new_col));   
            }
        }

        return memo[row][col] = ans + 1;
    }
};