bool isMatch(char *s, char *p)
{
    int n = strlen(s);
    int m = strlen(p);

    int **dp = (int **)malloc(sizeof(int *) * (n + 1));
    for (int i = 0; i <= n; ++i)
    {
        dp[i] = malloc(sizeof(int) * (m + 1));
        memset(dp[i], 0, sizeof(int) * (m + 1));
    }

    dp[0][0] = 1;
    for (int i = 2; i <= m && p[i - 1] == '*'; i += 2)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (p[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2];
                if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
    }

    return dp[n][m];
}