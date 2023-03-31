class Solution
{
public:
    // 大等差解决方案
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> dp;

        int ans = 2;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int step = nums[i] - nums[j];
                int ikey = i | ((unsigned int)step << 10);
                int jkey = j | ((unsigned int)step << 10);
                int dpj = dp.count(jkey) ? dp[jkey] : 1;
                dp[ikey] = max(dpj + 1, dp[ikey]);

                ans = max(dp[ikey], ans);
            }
        }

        return ans;
    }
};

class Solution
{
public:
    // 考虑到数据范围比较小，可以写死一个最大等差
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i][step]表示已nums[i]为结尾且等差为step的最长等差数列长度
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int ans = 2;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int step = nums[i] - nums[j] + 500;

                dp[i][step] = dp[j][step] + 1;
                ans = max(ans, dp[i][step]);
            }
        }

        return ans;
    }
};