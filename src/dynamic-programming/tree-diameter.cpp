class Solution {
public:
    int ans = 0;
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        //dfs(graph, visited, source)表示以source为根的子树的最大深度
        //假设source的直接子节点为[neighbor1, neighbor2, neighbor3]，并且
        //a = dfs(x,x,neightbor1)
        //b = dfs(x,x,neightbor2)
        //c = dfs(x,x,neightbor3)
        //此时如果我们要求一条经过source的最长路径,我们只需要求
        //max(a,b,c) + second_max(a,b,c) + 1即可，也就是以source为根的子树的
        //最大深度和以source为根的子树的第二大深度之和加1
        dfs(graph, visited, 0);
        
        return ans;
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int source) {
        if (visited[source]) return 0;
        visited[source] = true;

        int max1 = 0;
        int max2 = 0;
        for (int neighbor : graph[source]) {
            if (!visited[neighbor]) {
                int num = dfs(graph, visited, neighbor);

                if (num > max1) {
                    max2 = max1;
                    max1 = num;
                }
                else if (num > max2) {
                    max2 = num;
                }
            }
        }

        //用最大深度和次大深度之和更新答案
        ans = max(ans, max1 + max2);

        return max1 + 1;
    }
};