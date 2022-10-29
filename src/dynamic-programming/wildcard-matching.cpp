class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for(int i = 1; i <= m && p[i - 1] == '*'; ++i) dp[0][i] = true;

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
    }
};

class Solution {
public:
    inline bool isAllStars(string &s, int start, int len) {
        for(int i = start; i < len; ++i) {
            if(s[i] != '*') {
                return false;
            }
        }

        return true;
    }

    inline bool charMatch(char s, char p) {
        return s == p || p == '?';
    }

    bool isMatch(string s, string p) {
        int sLen = s.size();
        int pLen = p.size();
        int sIndex = 0;
        int pIndex = 0;

        while(sLen && pLen && p[pLen - 1] != '*') {
            if(charMatch(s[sLen - 1], p[pLen - 1])) {
                --sLen;
                --pLen;
            } 
            else {
                return false;
            }
        }

        if(!pLen) {
            return !sLen;
        }

        int sRecord = -1;
        int pRecord = -1;
        while(sIndex < sLen && pIndex < pLen) {
            if(charMatch(s[sIndex], p[pIndex])) {
                ++sIndex;
                ++pIndex;
            }
            else if(p[pIndex] == '*') {
                sRecord = sIndex;
                ++pIndex;
                pRecord = pIndex;
            }
            else if(sRecord != -1 && sRecord + 1 < sLen) {
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else {
                return false;
            }
        }

        return isAllStars(p, pIndex, pLen);
    }
};