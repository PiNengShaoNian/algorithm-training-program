const int MOD = 1'000'000'007;
const int MX = 100'001;

long long f[MX], g[MX];

int init = []() {
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < MX; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
        g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string s) {
        // 让我们先从最简单的情况考虑，假如只有一种数字比如2,要求一个长度为n且数字都为2的字符串可能表示的信息种类
        // 其思路和上楼梯(一次可以选择上一个两个或者三个楼梯)思路相同dp[i]表示长度为i的楼梯的上楼方案数
        // 回到这个问题我们可以把这个问题中的字符串按照连续的相同字符合并同类项然后再将它们分割这个问题就变成
        // 了计算若干个子上楼梯问题，然后他们的积就是这个问题的答案
        long long ans = 1;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            cnt++;
            if (i == s.size() - 1 || c != s[i + 1]) {
                ans = ans * (c != '7' && c != '9' ? f[cnt] : g[cnt]) % MOD;
                cnt = 0;
            }
        }
        return ans;
    }
};