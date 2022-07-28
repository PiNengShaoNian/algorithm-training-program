class Solution {
public:
    //LIS模板题
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //dp[i]表示以words[i]结尾的词链的最大长度
        vector<int> dp(n, 1);
        sort(words.begin(), words.end(), [](auto &a, auto& b) -> bool {
            return a.size() < b.size();
        });
        int ans = 1;

        for(int i = 1; i < n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                int leni = words[i].size();
                int lenj = words[j].size();
                if(leni == lenj) continue;
                if(leni - lenj > 1) break;
                int skipOne = false;
                int idxi = 0;
                int idxj = 0;
                //判断是否是连续的词链
                while(idxi < leni) {
                    if(words[i][idxi] == words[j][idxj]) {
                        ++idxi;
                        ++idxj;
                    }
                    else if(!skipOne) {
                        ++idxi;
                        skipOne = true;
                    }
                    else {
                        break;
                    }
                }

                //如果是连续的就更新答案
                if(idxi == leni) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};