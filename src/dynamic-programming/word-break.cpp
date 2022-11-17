class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        int n = s.size();
        // dp[i]表示字符串s[0:i-1]能否由wordDict中的单词组成
        vector<bool> dp(n + 1, false);
        for(auto s : wordDict) {
            wordSet.insert(s);
        }

        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};