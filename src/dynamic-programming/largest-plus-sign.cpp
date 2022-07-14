class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        unordered_set<int> banned;
        int ans = 0;
        //dp[i][j]表示以(i,j)为中心点，向上下左右做延伸能形成加号标志的阶
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        for(auto& x : mines) {
            banned.insert(x[0] * n + x[1]);
        }

        for(int r = 0; r < n; ++r) {
            int count = 0;
            //计算[r,c]的右臂长
            for(int c = 0; c < n; ++c) {
                count = banned.count(r * n + c) ? 0 : count + 1;
                dp[r][c] = count;
            }

            count = 0;
            //计算[r,c]的左臂长
            for(int c = n - 1; c >= 0; --c) {
                count = banned.count(r * n + c) ? 0 : count + 1;
                dp[r][c] = min(count, dp[r][c]);
            } 
        }

        for(int c = 0; c < n; ++c) {
            int count = 0;
            //计算[r,c]的下臂长
            for(int r = 0; r < n; ++r) {
                count = banned.count(r * n + c) ? 0 : count + 1;
                dp[r][c] = min(count, dp[r][c]);
            }
            
            count = 0;
            //计算[r,c]的上臂长
            for(int r = n - 1; r >= 0; --r) {
                count = banned.count(r * n + c) ? 0 : count + 1;
                dp[r][c] = min(count, dp[r][c]);
                ans = max(ans, dp[r][c]);
            }
        }

        return ans;
    }
};