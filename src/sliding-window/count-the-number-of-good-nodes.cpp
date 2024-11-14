class Solution {
private:
    struct CountInfo {
        int goodCount;
        int nodeCount;
    };
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n + 1);

        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return countGoodNodes(graph, 0, -1).goodCount;
    }

    CountInfo countGoodNodes(vector<vector<int>> &graph, int node, int parent) {
        int subTreeSize = 0;
        int nodeCount = 0;
        int isValid = true;
        int goodCount = 0;
        for (int adj : graph[node]) {
            if (adj == parent) {
                continue;
            }
             CountInfo subInfo = countGoodNodes(graph, adj, node);
             if (subTreeSize == 0) {
                subTreeSize = subInfo.nodeCount;
             } else if (subTreeSize != subInfo.nodeCount) {
                isValid = false;
             }
             nodeCount += subInfo.nodeCount;
             goodCount += subInfo.goodCount;
        }

        return CountInfo {
            .goodCount = goodCount + (isValid ? 1 : 0),
            .nodeCount = nodeCount + 1,
        };
    }
};