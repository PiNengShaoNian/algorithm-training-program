class Solution {
public:
    //O(N ^ 3)解法
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = 0; i < n; ++i) {
            dp[0][i] = grid[0][i];
        }

        for(int i = 1; i < n; ++i) {
            for(int  j = 0; j < n; ++j) {
                int min_value = 1e9;
                for(int k = 0; k < n; ++k) {
                    if(k != j) {
                        min_value = min(min_value, dp[i - 1][k]);
                    }
                } 


                dp[i][j] = grid[i][j] + min_value;
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }

    //优化解法时间复杂度O(N ^ 2)
    int minFallingPathSum1(vector<vector<int>>& grid) {
        //上面的解法的最内侧循环，大部分情况下都在做同样的事情(选择出前一行的最小值)，不难看出
        //我们只用记录前一行的最小的值，和次小的值，就足够了，在当前行的列j
        //不等于前一行最小值所在列的值的时候我们直接加上前一行的最小值即可
        //如果等于我们就选择加上前一行的次小值
        
        //前一行的累计最小和
        int prev_first_sum = 0;
        //前一行的累计最小和所在的列
        int prev_first_pos = -1;
        //前一行的累计次小和
        int prev_second_sum = 0;
        int n = grid.size();

        for(int i = 0; i < n; ++i) {
            int curr_first_sum = INT_MAX;
            int curr_first_pos = -1;
            int curr_second_sum = INT_MAX;
            for(int j = 0; j < n; ++j) {
                int cur_sum = (j != prev_first_pos ? prev_first_sum : prev_second_sum) + grid[i][j];
                
                //每一次迭代都更新，当前行的最小值和最小值所在的列，和次小值
                if(cur_sum < curr_first_sum) {
                    curr_second_sum = curr_first_sum;
                    curr_first_sum = cur_sum;
                    curr_first_pos = j;
                }
                else if(cur_sum < curr_second_sum) {
                    curr_second_sum = cur_sum;
                }
            }

            //在这次迭代结束之前，将当前行的信息保存到prev中
            prev_first_sum = curr_first_sum;
            prev_first_pos = curr_first_pos;
            prev_second_sum = curr_second_sum;
        }

        return prev_first_sum;
    }
};