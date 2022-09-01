//剑指 Offer 60. n个骰子的点数
class Solution {
public:
    vector<double> dicesProbability(int n) {
        //dp[i][j]表示投完第i枚骰子后，点数为j可能出现的次数
        int dp[12][67];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= 6; ++i) {
            dp[1][i] = 1;
        }

        for(int i = 2; i <= n; ++i) {
            for(int j = i; j <= 6 * i; ++j) {
                for(int cur = 1; cur <= 6; ++cur) {
                    if(j - cur < 1) break;

                    dp[i][j] += dp[i - 1][j - cur]; 
                }
            }
        }

        int all = pow(6, n);
        vector<double> ans;
        for(int i = n; i <= n * 6; ++i) {
            ans.push_back(dp[n][i] * 1.0 / all);
        }

        return ans;
    }
};