class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        //从叶子节点开始bfs，遍历到最后一层的节点就是最小高度的树的可能根节点
        vector<int> degress(n, 0);
        vector<vector<int>> graph(n);

        for(auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];
            ++degress[a];
            ++degress[b];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;

        for(int i = 0;i < n; ++i) {
            if(degress[i] ==1) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.clear();
            int size = q.size();
            for(int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                ans.push_back(cur);

                for(int neighbor : graph[cur]) {
                    if(--degress[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        return ans;
    }
};