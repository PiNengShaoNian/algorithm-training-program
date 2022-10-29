class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for(int i = 2; i <= m && p[i - 1] == '*'; i += 2) {
            dp[0][i] = true;
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2];
                    if(p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }

        return dp[n][m];
    }
};