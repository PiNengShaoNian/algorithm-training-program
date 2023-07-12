class Solution
{
public:
    string longestPalindrome(string s)
    {
        int ansLen = 1;
        int ansStart = 0;
        int n = s.size();

        for (int i = 1; i < n; ++i)
        {
            int l = i - 1;
            int r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                --l;
                ++r;
            }

            if (r - l - 1 > ansLen)
            {
                ansStart = l + 1;
                ansLen = r - l - 1;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            int l = i;
            int r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                --l;
                ++r;
            }

            if (r - l - 1 > ansLen)
            {
                ansStart = l + 1;
                ansLen = r - l - 1;
            }
        }

        return s.substr(ansStart, ansLen);
    }
};

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxLen = 1;
        int start = 0;
        int end = 0;

        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len <= n; i++)
            {
                int j = i + len - 1;

                if (len == 1)
                {
                    dp[i][i] = 1;
                }
                else if (len == 2)
                {
                    dp[i][j] = s[i] == s[j];
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }

                if (dp[i][j] && len > maxLen)
                {
                    maxLen = len;
                    start = i;
                    end = j;
                }
            }
        }

        return string(s.begin() + start, s.begin() + end + 1);
    }
};