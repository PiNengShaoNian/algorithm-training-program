class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        //dp[i]表示在stoneValue[i,n-1]区间内先手能获得的最大石子
        vector<int> dp(n, INT_MIN);

        //stoneValue[i,n-1]区间内的所有石子之和
        int sum = 0;
        //i从大到小递推这样dp[i+j]最是子状态
        for(int i = n - 1; i >= 0; --i) {
            sum += stoneValue[i];

            //由于石子堆里面的石子数量可能有负数，所以必须特别处理n-1,n-2,n-3这三种基础情况(对应只有一堆石子，两堆石子，三堆石子)
            //如果没有负数则这三种基础情况的dp[i]都为sum
            //只有一堆石子
            if(i == n - 1) {
                dp[i] = sum;
            }
            //有两堆石子
            else if(i == n - 2) {
                //判断拿走一堆划算还是两堆
                dp[i] = max(stoneValue[i], sum);
            }
            //有三堆
            else if(i == n - 3) {
                //判断拿走一堆，两堆还是三堆全拿走划算
                dp[i] = max(sum, max(sum - dp[i + 1], sum - dp[i + 2]));
            }
            else {
                for(int j = 1; j <= 3; ++j) {
                    dp[i] = max(sum - dp[i + j], dp[i]);
                }
            }
        }

        //如果先手的人能获得超过总石子数的一半说明Alice能获胜
        return dp[0] * 2 > sum ? "Alice" : dp[0] * 2 == sum ? "Tie" : "Bob";
    }
};