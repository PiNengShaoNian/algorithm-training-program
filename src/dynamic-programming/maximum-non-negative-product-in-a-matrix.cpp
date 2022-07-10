class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //dp_min[i][j]表示从[0,0]累计到[i,j]的最小乘积值
        vector<vector<long long>> dp_min(n, vector<long long>(m));
        //dp_max[i][j]表示从[0,0]累计到[i,j]的最大乘积值
        vector<vector<long long>> dp_max(n, vector<long long>(m));
        const long long MOD = 1e9 + 7;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 && j == 0) {
                    dp_min[0][0] = dp_max[0][0] = grid[0][0];
                }
                else if(i == 0) {
                    dp_min[i][j] = dp_max[i][j] = dp_min[i][j - 1] * grid[i][j] % MOD;
                }
                else if(j == 0) {
                    dp_min[i][j] = dp_max[i][j] = dp_min[i - 1][j] * grid[i][j] % MOD;
                }
                else {
                    if(grid[i][j] >= 0) {
                        dp_max[i][j] = max(dp_max[i - 1][j], dp_max[i][j - 1]) * grid[i][j];
                        dp_min[i][j] = min(dp_min[i - 1][j], dp_min[i][j - 1]) * grid[i][j];
                    }
                    else {
                        dp_min[i][j] = max(dp_max[i - 1][j], dp_max[i][j - 1]) * grid[i][j];
                        dp_max[i][j] = min(dp_min[i - 1][j], dp_min[i][j - 1]) * grid[i][j];          
                    }
                }
            }
        }

        long long ans = dp_max[n - 1][m - 1];
        return ans < 0 ? -1 : ans % MOD;
    }
};