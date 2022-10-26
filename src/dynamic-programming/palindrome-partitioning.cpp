class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> ans;
    vector<string> p;
    string s;
    int n;

    vector<vector<string>> partition(string _s) {
        s = move(_s);
        n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for(int len = 1; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if(len == 1) {
                    dp[i][j] = true;
                }
                else if(len == 2) {
                    dp[i][j] = s[i] == s[j];
                }
                else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
            }
        }

        dfs(0);

        return ans;
    }

    void dfs(int i) {
        if(i == n) {
            ans.push_back(p);
            return;
        }

        for(int j = i; j < n; ++j) {
            if(dp[i][j]) {
                p.push_back(s.substr(i, j - i + 1));
                dfs(j + 1);
                p.pop_back();
            }
        }
    }
};