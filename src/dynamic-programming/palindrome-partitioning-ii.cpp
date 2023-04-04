class Solution
{
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> g(n, vector<bool>(n, false));

        for (int len = 1; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;

                if (len == 1)
                {
                    g[i][j] = true;
                }
                else if (len == 2)
                {
                    g[i][j] = s[i] == s[j];
                }
                else
                {
                    g[i][j] = s[i] == s[j] && g[i + 1][j - 1];
                }
            }
        }

        vector<int> dp(n, INT_MAX);

        for (int i = 0; i < n; ++i)
        {
            if (g[0][i])
            {
                dp[i] = 0;
            }
            else
            {
                for (int j = 0; j < i; ++j)
                {
                    if (g[j + 1][i])
                        dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};