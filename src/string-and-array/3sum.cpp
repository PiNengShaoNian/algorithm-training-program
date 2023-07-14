class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool
             { return a < b; });

        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            vector<vector<int>> twoSums;

            twoSum(twoSums, nums, -nums[i], i + 1);
            for (auto &cand : twoSums)
            {
                cand.push_back(nums[i]);
                ans.emplace_back(move(cand));
            }
        }

        return ans;
    }

    void twoSum(vector<vector<int>> &twoSums, vector<int> &nums, int target, int start)
    {
        int l = start;
        int r = nums.size() - 1;
        int n = nums.size();
        for (; l < n; ++l)
        {
            if (l > start && nums[l] == nums[l - 1])
                continue;

            while (l < r && nums[l] + nums[r] > target)
            {
                --r;
            }

            if (l < r && nums[l] + nums[r] == target)
            {
                twoSums.push_back(vector<int>{nums[l], nums[r]});
            }
        }
    }
};