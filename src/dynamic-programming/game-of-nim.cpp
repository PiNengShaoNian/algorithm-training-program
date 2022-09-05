//状态压缩dp解法
class Solution {
public:
    int n;
    //piles[i]最大为7所以piles当前的状态可以用piles.length * 3位bit表示
    //dp[i]表示当前的石子状态为i时,先手的人是否能取胜
    vector<int> dp;
    bool nimGame(vector<int>& piles) {
        n = piles.size();
        dp = vector<int>(1 << (3 * n), -1);

        //基础状态，处于一个石子都没没有的状态时，先手的人一定会输
        dp[0] = 0;
        int s = 0;
        for(int i = 0; i < n; ++i) {
            s += (piles[i] << (3 * i));
        }

        solve(s);

        return dp[s] == 1;
    }

    //状态转移dp[s] = !(dp[所有能从s到达的下一个状态])
    int solve(int s) {
        if(dp[s] != -1)
            return dp[s];

        for(int i = 0; i < n; ++i) {
            int m = (s >> (3 * i)) & 7;
            for(int j = 0; j < m; ++j) {
                int next = (j << (3 * i)) + (s & ~(7 << (3 * i)));

                //只有next存在一个状态会输，那么s就能赢
                if(solve(next) == 0) {
                    return dp[s] = 1;
                }
            }
        }

        return dp[s] = 0;
    }
};