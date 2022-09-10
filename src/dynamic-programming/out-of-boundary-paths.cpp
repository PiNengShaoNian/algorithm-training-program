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

class Solution1 {
public:
    int mod = 1000000007;
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans = 0;
        // dp[i][j][k]表示由起点(startRow,startColumn)经过k步走动(i,j)总共有多少条路径
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        dp[startRow][startColumn][0] = 1;

        for(int step = 1; step <= maxMove; ++step) {
            for(int i = 0; i < m; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dp[i][j][step - 1] == 0) continue;
                    for(int k = 0; k < 4; ++k) {
                        int new_row = i + dirs[k][0];
                        int new_col = j + dirs[k][1];

                        if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n) {
                            ans += dp[i][j][step - 1];
                            ans %= mod;
                        }
                        else {
                            dp[new_row][new_col][step] += dp[i][j][step - 1];
                            dp[new_row][new_col][step] %= mod; 
                        }
                    }
                }
            }
        }

        return ans;
    }
};