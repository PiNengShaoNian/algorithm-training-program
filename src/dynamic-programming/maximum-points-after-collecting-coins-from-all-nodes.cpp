class Solution {
private:
    // meme[node][f]表示已node为根节点的子树中，并且当已经有f次除2操作能获得的最大金币数量
    vector<vector<int>> memo;
    vector<vector<int>> children;
public:
    int dfs(int parent, int node, int f, vector<int> &coins, int k) {
        if (memo[node][f] >= 0) {
            return memo[node][f];
        }
        int res1 = (coins[node] >> f) - k;
        int res2 = (coins[node] >> (f + 1));
        for (int child : children[node]) {
            if (child == parent) {
                continue;
            }
            res1 += dfs(node, child, f, coins, k);
            if (f + 1 < 14) {
                res2 += dfs(node, child, f + 1, coins, k);
            }
        }
        return memo[node][f] = max(res1, res2);
    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        int n = coins.size();
        children = vector<vector<int>>(n);
        for (const auto &edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }
        memo = vector<vector<int>>(n, vector<int>(14, -1));
        return dfs(-1, 0, 0, coins, k);
    }
};