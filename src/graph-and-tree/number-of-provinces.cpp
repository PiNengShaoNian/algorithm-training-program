//深度优先搜索，求联通分量数量
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n, vector<int>());

        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; ++i) {
            if(!visited[i]) {
                dfs(visited, graph, i);
                ++count;
            }
        }

        return count;
    }

    void dfs(vector<bool>& visited, vector<vector<int>> &graph, int cur) {
        visited[cur] = true;
        for(auto neighbor : graph[cur]) {
            if(!visited[neighbor]) {
                dfs(visited, graph, neighbor);
            }
        }
    }
};

//并查集，求联通分量
class Solution {
public:
    vector<int> fa;
    int find(int x) {
        if(fa[x] == x) return x;

        return fa[x] = find(fa[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        fa.resize(n);
        for(int i = 0; i < n; ++i) {
            fa[i] = i;
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(isConnected[i][j] == 1) {
                    fa[find(i)] = find(j);
                }
            }
        }

        int ans = 0;

        for(int i = 0; i < n; ++i) {
            if(fa[i] == i) ++ans;
        }

        return ans;
    }
};