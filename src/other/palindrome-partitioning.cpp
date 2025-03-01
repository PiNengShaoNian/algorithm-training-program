class Solution {
    private:
        vector<vector<int>> dp;
        int n;
        void dfs(vector<vector<string>> &ans, string &s, int i, vector<string> &cur) {
            if (i == n) {
                ans.push_back(cur);
                return;
            }
    
            for (int j = i; j < n; j++) {
                if (dp[i][j]) {
                    cur.push_back(s.substr(i, j - i + 1));
                    dfs(ans, s, j + 1, cur);
                    cur.pop_back();
                }
            }
        }
    public:
        vector<vector<string>> partition(string s) {
            n = s.size();
            dp = vector<vector<int>>(n, vector<int>(n, false));
    
            for (int len = 1; len <= n; len++) {
                for (int i = 0; i + len <= n; i++) {
                    int j = i + len - 1;
                    if (len == 1) {
                        dp[i][i] = true;
                    } else if (len == 2) {
                        dp[i][j] = s[i] == s[j];
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    }
                }
            }
    
            vector<vector<string>> ans;
            vector<string> cur;
            dfs(ans, s, 0, cur);
            return ans;
        }
    };