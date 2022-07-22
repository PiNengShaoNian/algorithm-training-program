class Solution {
public:
    vector<vector<int>> label_count;
    vector<vector<int>> graph;
    vector<int> ans;
    string labels;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string _labels) {
        graph = vector<vector<int>>(n, vector<int>());
        label_count = vector<vector<int>>(n, vector<int>(26, 0));
        ans = vector<int>(n);
        labels.assign(move(_labels));
        
        //建图
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);

        return ans;
    }

    //自底向上为每一个节点累加标签数量
    void dfs(int cur, int pre) {
        ++label_count[cur][labels[cur] - 'a'];

        for(int child : graph[cur]) {
            if(child == pre) continue;
            dfs(child, cur);
            auto& cur_count = label_count[cur];
            auto& child_count = label_count[child];

            for(int i = 0; i < 26; ++i) {
                cur_count[i] += child_count[i];
            }
        }

        ans[cur] = label_count[cur][labels[cur] - 'a'];
    }
};