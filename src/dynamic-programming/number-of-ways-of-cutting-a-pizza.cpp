class Solution {
public:
    int MOD = 1e9 + 7;
    int memo[50][50][10];
    int presum[51][51];
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        memset(memo, -1, sizeof(memo));
        memset(presum, 0, sizeof(presum));
  
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                presum[i][j] = (pizza[i][j] == 'A' ? 1 : 0) + presum[i + 1][j] + presum[i][j + 1] - presum[i + 1][j + 1];
            }
        }

        return dfs(0, 0, k - 1, n, m);
    }

    int dfs(int row, int col, int remain, int rows, int cols) {
        if(remain == 0) {
            return presum[row][col] > 0 ? 1 : 0;
        }

        if(memo[row][col][remain] != -1) return memo[row][col][remain];

        int ans = 0;

        for(int i = row + 1; i < rows; ++i) {
            //要保证切出来的[row,i)中有苹果，如果这里相等则说明没有，则继续枚举
            //下一个i
            if(presum[row][col] == presum[i][col]) continue;

            ans = (ans + dfs(i, col, remain - 1, rows, cols)) % MOD;
        }

        for(int j = col + 1; j < cols; ++j) {
            //要保证切出来的[col,j)中有苹果，如果这里相等则说明没有，则继续枚举
            //下一个j
            if(presum[row][col] == presum[row][j]) continue;

            ans = (ans + dfs(row, j, remain - 1, rows, cols)) % MOD;
        }

        return memo[row][col][remain] = ans;
    }
};