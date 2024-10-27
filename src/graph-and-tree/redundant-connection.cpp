class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> fa(n + 1);
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
        function<int (int)> find = [&](int x) -> int {
            if (fa[x] == x) {
                return x;
            }
            return fa[x] = find(fa[x]);
        };
        auto connect = [&](int a, int b) {
            fa[find(a)] = find(b);
        };


        for (vector<int> &edge : edges) {
            int a = edge[0];
            int b = edge[1];
            if (find(a) == find(b)) {
                return edge;
            } else {
                connect(a, b);
            }
        }
        return {};
    }
};