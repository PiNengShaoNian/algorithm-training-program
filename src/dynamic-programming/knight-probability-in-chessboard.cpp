class Solution {
public:
    vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    double knightProbability(int n, int k, int row, int column) {
        //dp[k][row][column]表示从棋盘上任意一点出发后经过k次 能到达row column的概率之和 所以最后直接返回dp[k][row][column]
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n,vector<double>(n)));
        
        for(int step = 0; step <= k; ++step) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(step == 0) {
                        dp[0][i][j] = 1.0;
                    }
                    else {
                        for(auto &dir : dirs) {
                            int ni = i + dir[0];
                            int nj = j + dir[1];

                            if(ni >= 0 && ni < n && nj >= 0 && nj <n) {
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
                            }
                        }
                    }
                }
            }
        }

        return dp[k][row][column];
    }
};