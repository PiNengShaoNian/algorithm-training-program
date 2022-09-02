class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(n == 1) return 1.0;
        vector<vector<int>> graph(n + 1);
        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        //dp[i][j]表示t秒过后青蛙在节点j上的概率
        vector<vector<double>> dp(t + 1, vector<double>(n + 1, 0.0));

        dp[0][1] = 1;

        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(1);
        int depth = 1;
        while(depth <= t) {
            //层序遍历逻辑，其中next_depth_q存储的就是下一层级的元素
            queue<int> next_depth_q;
            while(q.size()) {
                int cur = q.front();
                q.pop();
                visited[cur] = true;
    
                //如果是根节点他的子节点数量就是他的size，如果不是根节点他的子节点数量还需要减去父节点
                int child_count = cur == 1 ? graph[cur].size() : graph[cur].size() - 1;
                for(auto neighbor : graph[cur]) {
                    if(visited[neighbor]) continue;

                    dp[depth][neighbor] = dp[depth - 1][cur] / child_count;
                    next_depth_q.push(neighbor);

                    //如果已经到达了叶子节点无论再过几秒他都会留在原地所以
                    //可以dp[t][neighbor]就由此时的dp[depth][neighbor]决定
                    if(graph[neighbor].size() == 1) {
                        dp[t][neighbor] = dp[depth][neighbor];
                    }
                }
            }

            q = move(next_depth_q);
            ++depth;
        }

        return dp[t][target];
    }
};