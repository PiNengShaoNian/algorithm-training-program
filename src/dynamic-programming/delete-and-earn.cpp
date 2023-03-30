class Solution
{
public:
    struct Pair
    {
        // 数值
        int first;
        // 该数值出现的次数
        int second;
    };

    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool
             { return a < b; });

        int n = nums.size();
        vector<Pair> pairs;
        Pair pair = {nums[0], 1};

        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == pair.first)
            {
                pair.second++;
            }
            else
            {
                pairs.push_back(pair);
                pair = (Pair){nums[i], 1};
            }
        }

        pairs.push_back(pair);

        if (pairs.size() == 1)
            return pairs[0].first * pairs[0].second;

        vector<int> dp(pairs.size());

        int score0 = pairs[0].first * pairs[0].second;
        int score1 = pairs[1].first * pairs[1].second;
        dp[0] = score0;
        dp[1] = pairs[1].first - pairs[0].first > 1 ? score0 + score1 : max(score0, score1);

        int m = pairs.size();

        for (int i = 2; i < m; ++i)
        {
            dp[i] = max(
                dp[i - 1],
                pairs[i].first * pairs[i].second + (pairs[i].first - pairs[i - 1].first > 1
                                                        ? dp[i - 1]
                                                        : dp[i - 2]));
        }

        return dp[m - 1];
    }
};

class Solution1
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int max_num = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            max_num = max(max_num, nums[i]);
        }

        vector<int> scores(max_num + 1, 0);

        for (int num : nums)
        {
            scores[num] += num;
        }

        return rob1(scores);
    }

    int rob1(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        // dp[i]表示只在前i + 1家偷能获得的最大收益
        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i)
        {
            dp[i] = max(
                // 不偷这家,那就能在[0, i-1]区间内偷
                dp[i - 1],
                // 偷这家，那之前就只能在[0,i-2]区间内偷
                nums[i] + dp[i - 2]);
        }

        return dp[n - 1];
    }
};