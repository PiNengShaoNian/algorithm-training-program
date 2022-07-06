class Solution {
public:
    //正着推
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        dp[0] = vector<int>(1,triangle[0][0]);

        for(int i = 1; i < n; ++i) {
            int w = triangle[i].size();
            int prev_w = triangle[i - 1].size();
            dp[i] = vector<int>(w, 1e9);

            for(int j = 0; j < w; ++j) {
                if(j < prev_w) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }

                if(j - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                }
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end()); 
    }

    //倒着推
    int minimumTotal1(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int depth = n - 2; depth >= 0; --depth) {
            int len = triangle[depth].size();
            for(int i = 0; i < len; ++i) {
                triangle[depth][i] = triangle[depth][i] + min(triangle[depth + 1][i], triangle[depth + 1][i + 1]);
            }
        }

        return triangle[0][0];
    }
};