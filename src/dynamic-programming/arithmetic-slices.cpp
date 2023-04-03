class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int ans = 0;
        int t = 0;

        for (int i = 2; i < n; ++i)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                ans += ++t;
            }
            else
            {
                t = 0;
            }
        }

        return ans;
    }
};