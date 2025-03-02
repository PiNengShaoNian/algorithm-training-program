class Solution {
    public:
        int minCut(string s) {
            int n = s.size();
            vector<vector<int>> g(n, vector<int>(n, false));
    
            for (int len = 1; len <= n; len++) {
                for (int i = 0; i + len <= n; i++) {
                    int j = i + len - 1;
                    if (len == 1) {
                        g[i][i] = true;
                    } else if (len == 2) {
                        g[i][j] = s[i] == s[j];
                    } else {
                        g[i][j] = g[i + 1][j - 1] && s[i] == s[j];
                    }
                }
            }
    
            vector<int> f(n, INT_MAX);
            for (int i = 0; i < n; i++) {
                if (g[0][i]) {
                    f[i] = 0;
                } else {
                    for (int j = 0; j < i; j++) {
                        if (g[j + 1][i]) {
                            f[i] = min(f[i], f[j] + 1);
                        }
                    }
                }
            }
    
            return f[n - 1];
        }
    };