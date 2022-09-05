//状态压缩dp
class Solution {
public:
    //考虑到字符串最长只有60,所以可以用60位bit表示该字符串对于的状态(用long long)
    unordered_map<int,int> dp;
    //字符串长度
    int n;
    bool canWin(string currentState) {
        n = currentState.size();

        long long s = 0;
        for(int i = 0; i < n; ++i) {
            //'+'用1表示'-'用0表示
            s += ((currentState[i] == '+' ? 1ll : 0ll) << i);
        }

        return solve(s) == 1;
    }

    //递推公式dp[s] = !(dp[next1] && dp[next2] && ... && dp[next_n])
    //其中next状态是所有能从s到达的下一个状态
    int solve(long long s) {
        if(dp.count(s)) return dp[s];

        for(int i = 0; i < n - 1; ++i) {
            //有连续的'+'将其翻转并到达下一个状态
            if(((1ll << i) & s ) && ((1ll << i + 1) & s)) {
                long long next = ~(3ll << i) & s;
                if(solve(next) == 0) {
                    return dp[s] = 1;
                } 
            }
        }

        return dp[s] = 0;
    }
};