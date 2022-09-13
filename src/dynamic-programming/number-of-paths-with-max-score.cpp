class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        //dp[i][j]表示从[n-1,n-1]到[i,j]的最大路径和
        vector<vector<int>> dp(n, vector<int>(n, -1));
        //count[i][j]表示从[n-1,n-1]到[i,j]的最大路径和的数量
        vector<vector<int>> count(n, vector<int>(n, 0));
        board[0][0] = '0';
        int MOD = 1e9 + 7;

        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(board[i][j] == 'X') {
                    continue;
                }

                if(i == n - 1 && j == n - 1) {
                    dp[i][j] = 0;
                    count[i][j] = 1;
                }
                else if(i == n - 1) {
                    int prev = dp[i][j + 1];
                    dp[i][j] = prev == -1 ? -1 :  (board[i][j] - '0') + prev;
                    count[i][j] = count[i][j + 1];
                }
                else if(j == n - 1) {
                    int prev = dp[i + 1][j];
                    dp[i][j] = prev == -1 ? -1 : (board[i][j] - '0') + prev;
                    count[i][j] = count[i + 1][j];
                }
                else {
                   int right = dp[i][j + 1];
                   int bottom = dp[i + 1][j];
                   int right_bottom = dp[i + 1][j + 1];
                   
                   int max_precursor = max(right, max(bottom, right_bottom));

                   if(max_precursor != -1) {
                       if(right == max_precursor) {
                           count[i][j] = (count[i][j] + count[i][j + 1]) % MOD;
                       }

                       if(bottom == max_precursor) {
                           count[i][j] = (count[i][j] + count[i + 1][j]) % MOD;
                       }

                       if(right_bottom == max_precursor) {
                           count[i][j] = (count[i][j] + count[i + 1][j + 1]) % MOD;
                       }

                       dp[i][j] = (board[i][j] - '0') + max_precursor;
                   }
                }
            }
        }

        if(dp[0][0] == -1) return {0, 0};

        return {dp[0][0], count[0][0] % MOD};
    }
};

class Solution1 {
public:
    using score_path = pair<int,int>;
    int mod = 1000000007;

    void update(vector<vector<score_path>>& dp, int n, int row_adj, int col_adj, int row, int col) {
        if(row_adj >= n || col_adj >= n || dp[row_adj][col_adj].first == -1) {
            return;
        }

        if(dp[row_adj][col_adj].first > dp[row][col].first) {
            dp[row][col] = dp[row_adj][col_adj];
        }
        else if(dp[row_adj][col_adj].first == dp[row][col].first){
            dp[row][col].second += dp[row_adj][col_adj].second;
            dp[row][col].second %= mod;
        }
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<score_path>> dp(n, vector<score_path>(n, {-1, 0}));

        dp[n - 1][n - 1] = {0, 1};
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                if(!(i == n - 1 && j == n - 1) && board[i][j] != 'X') {
                    update(dp, n, i + 1, j, i, j);
                    update(dp, n, i, j + 1, i, j);
                    update(dp, n, i + 1, j + 1, i, j);

                    if(dp[i][j].first != -1) {
                        dp[i][j].first += (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }

        return dp[0][0].first == -1 ? vector<int>{0, 0} : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};