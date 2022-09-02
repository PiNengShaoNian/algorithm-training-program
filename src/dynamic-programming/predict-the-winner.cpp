class Solution {
public:
    vector<int> nums;
    unordered_map<int,int> memo;
    bool PredictTheWinner(vector<int>& _nums) {
        nums = move(_nums);

        return dfs(0, nums.size() - 1, 1) >= 0;
    }

    //turn为1表示A先手，为-1表示B先手
    //dfs(l,r,1)表示在nums[l:r]范围内，在A先手的情况下，A,B都尝试
    //使自己得到的分数最大，最后A,B两者分数的差值是多少
    //我们可以让A赚正分，B赚负分，最后的结果就是他们两的和是否大于零
    int dfs(int l, int r, int turn) {
        if(l == r) {
            return turn * nums[l];
        }

        //数组最大长度为20,l和r都可以用5bit容纳
        int key =  (l << 6) | (r << 1) | (turn > 0 ? 1 : 0);

        if(memo.count(key)) {
            return memo[key];
        }

        int startScore = nums[l] * turn + dfs(l + 1, r, -turn);
        int endScore = nums[r] * turn + dfs(l, r - 1, -turn);

        return memo[key] = (turn == 1 ? 
                                //这轮是A做选择，他要选择其中较大的分使自己的分数成为一个更大的正数
                                //这样他才能获胜
                                max(startScore, endScore) : 
                                //这轮是B做选择，他要选择其中较小的分使自己的分数成为一个更小的负数
                                //这样他才能获胜
                                min(startScore, endScore));
    }

    //动态规划解法
    bool PredictTheWinner1(vector<int>& nums) {
        int n = nums.size();
        //dp[i][j]表示在nums[i:j]区间内先手的那个玩家能比后手的玩家多多少分
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= n; ++len) {
            for(int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                
                //如果一个人在nums[i:j]区间内选择先手，它可以选择nums[i]或者nums[j]
                //那么我们需要减去一个人在nums[i+1:j]或者nums[i:j-1]区间内先手
                //的领先分数，就是dp[i][j]
                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                );
            }
        }

        return dp[0][n - 1] >= 0;
    }
};