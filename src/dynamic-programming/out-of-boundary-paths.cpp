class Solution {
public:
    int MOD = 1000000007;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxMove + 1, vector<vector<int>>(m, vector<int>(n)));
        int ans = 0;
        //dp[move][i][j]表示从网格上的任何一点出发，经过move步，能到达网格上的第i行第j列路径的个数
        dp[0][startRow][startColumn] = 1;
        for(int move = 0; move < maxMove; ++move) {
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    int count = dp[move][i][j];

                    if(count > 0) {
                        for(auto &dir : directions) {
                            int ni = i + dir[0];
                            int nj = j + dir[1];

                            if(ni >= 0 && ni < m && nj >= 0 && nj < n) {
                                dp[move + 1][ni][nj] = (dp[move + 1][ni][nj] + count ) % MOD; 
                            }
                            else {
                                ans = (ans + count) % MOD;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};