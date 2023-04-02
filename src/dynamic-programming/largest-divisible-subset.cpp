class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool
             { return a < b; });

        int maxSize = 1;
        int maxVal = nums[0];
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxSize)
            {
                maxVal = nums[i];
                maxSize = dp[i];
            }
        }

        if (maxSize == 1)
        {
            return {maxVal};
        }

        vector<int> ans;
        for (int i = n - 1; i >= 0; --i)
        {
            if (maxSize == dp[i] && maxVal % nums[i] == 0)
            {
                --maxSize;
                maxVal = nums[i];
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};