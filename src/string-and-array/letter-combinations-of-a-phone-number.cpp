int numToChars['9' + 1][4] = {
    ['2'] = {'a', 'b', 'c'},
    ['3'] = {'d', 'e', 'f'},
    ['4'] = {'g', 'h', 'i'},
    ['5'] = {'j', 'k', 'l'},
    ['6'] = {'m', 'n', 'o'},
    ['7'] = {'p', 'q', 'r', 's'},
    ['8'] = {'t', 'u', 'v'},
    ['9'] = {'w', 'x', 'y', 'z'},
};
char path[5];
char path_idx = 0;

#define PATH_PUSH_CHAR(c) (path[path_idx++] = c)
#define PATH_POP_CHAR() (--path_idx)

class Solution
{
public:
    int n;
    string digits;
    vector<string> letterCombinations(string _digits)
    {
        if (_digits.size() == 0)
        {
            return vector<string>{};
        }

        vector<string> ans;
        n = _digits.size();
        digits = _digits;
        dfs(ans, 0);

        return ans;
    }

    void dfs(vector<string> &ans, int idx)
    {
        if (idx == n)
        {
            ans.push_back(string(path, path_idx));
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            PATH_PUSH_CHAR(numToChars[digits[idx]][i]);
            dfs(ans, idx + 1);
            PATH_POP_CHAR();
        }

        if (numToChars[digits[idx]][3])
        {
            PATH_PUSH_CHAR(numToChars[digits[idx]][3]);
            dfs(ans, idx + 1);
            PATH_POP_CHAR();
        }
    }
};