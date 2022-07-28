class Solution {
public:
    vector<vector<int>> memo;
    int weeks;
    int citys;
    //自顶向下记忆化搜索
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        citys = days.size();
        weeks = days[0].size();
        memo = vector<vector<int>>(citys, vector<int>(weeks, -1));

        return dfs(flights, days, 0, 0);
    }

    int dfs(vector<vector<int>>& flights, vector<vector<int>> &days, int cur_city, int week) {
        if(week == weeks) return 0;

        if(memo[cur_city][week] != -1) return memo[cur_city][week];

        int max_val = 0;
        for(int city = 0; city < citys; ++city) {
            if(flights[cur_city][city] == 1 || city == cur_city) {
                max_val = max(max_val, days[city][week] + dfs(flights, days, city, week + 1));
            }
        }

        return memo[cur_city][week] =  max_val;
    }

    //自底向上动态规划
    int maxVacationDays1(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int citys = days.size();
        int weeks = days[0].size();
        //dp[city][week]截止至第week周，处于city能获得的最大休假天数
        vector<vector<int>> dp(citys, vector<int>(weeks, INT_MIN));

        dp[0][0] = days[0][0];
        for(int i = 1; i < citys; ++i) {
            if(flights[0][i] == 1) {
                dp[i][0] = days[i][0];
            }
        }

        for(int w = 0; w < weeks - 1; ++w) {
            for(int i = 0; i < citys; ++i) {
                //对于第w周来说i是不可到达的，没必要基于这个状态往后递推了
                if(dp[i][w] < 0) continue;
                for(int j = 0; j < citys; ++j) {
                    if(flights[i][j] == 1 || i == j) {
                        dp[j][w + 1] = max(dp[j][w + 1], dp[i][w] + days[j][w + 1]); 
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < citys; ++i) {
            ans = max(ans, dp[i][weeks - 1]);
        }
        return ans;
    }
};