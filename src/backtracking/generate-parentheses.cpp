char path[17];
int path_idx = 0;
#define PUSH_CHAR(c) (path[path_idx++] = c)
#define POP_CHAR() (--path_idx)

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;

        dfs(ans, n, n);

        return ans;
    }

    void dfs(vector<string> &ans, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            ans.emplace_back(string(path, path_idx));
            return;
        }

        if (left >= right)
        {
            PUSH_CHAR('(');
            dfs(ans, left - 1, right);
            POP_CHAR();
        }
        else
        {
            if (left > 0)
            {
                PUSH_CHAR('(');
                dfs(ans, left - 1, right);
                POP_CHAR();
            }

            if (right > 0)
            {
                PUSH_CHAR(')');
                dfs(ans, left, right - 1);
                POP_CHAR();
            }
        }
    }
};