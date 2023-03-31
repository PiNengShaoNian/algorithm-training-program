class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> num_to_idx;

        for (int i = 0; i < n; ++i)
        {
            num_to_idx[arr[i]] = i;
        }

        unordered_map<int, int> dp;

        int ans = 0;
        for (int i = 2; i < n; ++i)
        {
            for (int j = i - 1; j >= 1; --j)
            {
                int first = arr[i] - arr[j];
                if (first >= arr[j])
                    break;
                if (num_to_idx.count(first))
                {
                    int first_idx = num_to_idx[first];

                    dp[i * n + j] = max(dp[i * n + j], dp[j * n + first_idx] + 1);
                    ans = max(ans, dp[i * n + j] + 2);
                }
            }
        }

        return ans < 3 ? 0 : ans;
    }
};