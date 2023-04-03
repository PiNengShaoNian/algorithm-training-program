class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, 0);

        int ans = 0;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                }
                else
                {
                    int left = i - dp[i - 1] - 1;
                    if (left >= 0 && s[left] == '(')
                    {
                        dp[i] = (left - 1 >= 0 ? dp[left - 1] : 0) + dp[i - 1] + 2;
                    }
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

class Solution1
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> stack;
        vector<char> valid(n, 1);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')
            {
                stack.push_back(i);
            }
            else
            {
                if (stack.empty())
                    valid[i] = 0;
                else
                    stack.pop_back();
            }
        }

        while (!stack.empty())
        {
            valid[stack.back()] = 0;
            stack.pop_back();
        }

        int ans = 0;
        int len = 0;
        for (int i = 0; i < n; ++i)
        {
            if (valid[i] == 0)
            {
                len = 0;
                continue;
            }
            ++len;
            ans = max(ans, len);
        }

        return ans;
    }
};