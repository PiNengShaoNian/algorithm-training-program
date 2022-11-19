//记忆化搜索
class Solution {
public:
    vector<vector<int>> memo;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        memo = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return dfs(1, n, nums);
    }

    int dfs(int l, int r, vector<int>& nums) {
        if(l > r) {
            return 0;
        }

        if(memo[l][r] != -1) return memo[l][r];

        int ans = 0;
        for(int i = l; i <= r; ++i) {
            // 选择i作为[l, r]区间内最后一个被戳破的气球,就可以写出递推公式
            // dp[l][r] = dp[l][i - 1] + dp[i + 1][r] + nums[l - 1] * nums[i] * nums[r + 1]
            // 由于知道nums[i]最后才被戳破，我们可以先计算他的子问题dp[l][i - 1]和dp[i + 1][r]，最后
            // 由于[l, r]区间的的球除了i都被戳破了，此时i的左右侧已经确定就是l-1和r+1
            ans = max(ans, dfs(l, i - 1, nums) + dfs(i + 1, r, nums) + nums[l - 1] * nums[i] * nums[r + 1]);
        }

        return memo[l][r] = ans;
    }
};

// 动态规划解法
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // dp[l][r]表示戳破区间[l, r]内所有气球能获得的最大分数
        vector<vector<int>> dp = vector<vector<int>>(n + 2, vector<int>(n + 2, 0));
        // 哨兵位
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // 枚举区间长度
        for(int len = 1; len <= n; ++len) {
            // 枚举区间左端点
            for(int l = 1; l + len <= n + 1; ++l) {
                // 计算区间右端点
                int r = l + len - 1;
                // 枚举该区间内最后戳破的一个位置
                for(int p = l; p <= r; ++p) {
                    // 由于p是[l, r]内最后戳破的，所以[l, p - 1]和[p + 1, r]的左右的元素
                    // 是确定的，他们可以作为子问题被提前计算出来，同理p作为区间内最后一个戳破的
                    // 所以它此时的左右一定是l - 1和r + 1,所以可以写出下面的递归公式
                    dp[l][r] = max(dp[l][r], dp[l][p - 1] + dp[p + 1][r] + nums[l - 1] * nums[p] * nums[r + 1]);
                }
            }
        }

        return dp[1][n];
    }
};