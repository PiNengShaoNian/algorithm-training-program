class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // memo[i][j]表示在前i个栈中选择j个硬币能得到的最大数值
        vector<vector<int>> memo(n, vector<int>(k + 1));
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0) {
                return 0;
            }
            int res = memo[i][j];
            if (res) {
                return res;
            }
            res = dfs(i - 1, j);
            int v = 0;
            for (int w = 0; w < min(j, (int)piles[i].size()); w++) {
                v += piles[i][w];
                res = max(res, dfs(i - 1, j - w - 1) + v);
            }
            return memo[i][j] = res;
        };
        return dfs(n - 1, k);
    }
};