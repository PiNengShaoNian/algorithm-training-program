class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<vector<int>> graph(n);
        int m = targetPath.size();
        //dp[v][i]表示终点为v长度为i + 1的路径和targetPath的最短编辑距离
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX / 2));
        vector<vector<int>> edit_path(n, vector<int>(m));

        //建图
        for(auto &edge : roads) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        //预处理每个name和targetPath中每个位置的编辑距离
        //如果相等编辑距离就为零，反之则为1
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                edit_path[i][j] = names[i] != targetPath[j];
            }
        }

        //路径长度为1时dp[i][0]和edit_path[i][0]等价
        for(int i = 0; i < n; ++i) {
            dp[i][0] = edit_path[i][0];
        }

        for(int i = 1; i < m; ++i) {
            for(int v = 0; v < n; ++v) {
                for(int u: graph[v]) {
                    //每一条从u到v的边，都存在在一个dp[u][i - 1]到dp[v][i]的状态转移
                    dp[v][i] = min(dp[v][i], dp[u][i - 1] + edit_path[v][i]);
                }
            }
        }

        //找到最小编辑距离路径的其中一个终点
        int end = -1;
        int min_path = INT_MAX / 2;
        for(int v = 0; v < n; ++v) {
            if(dp[v][m - 1] < min_path) {
                end = v;
                min_path = dp[v][m - 1];
            }
        }

        vector<int> ans(m);
        ans[m - 1] = end;
        int next_end = end;

        //由这个终点一路递推到起点，顺便将他们加入到ans中
        for(int i = m - 2; i >= 0; --i) {
            int u = -1;
            for(int v : graph[next_end]) {
                if(dp[v][i] == dp[next_end][i + 1] - edit_path[next_end][i + 1]) {
                    u = v;
                    break;
                }
            }

            next_end = u;
            ans[i] = u;
        }

        return ans;
    }
};