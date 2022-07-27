//状态压缩，动态规划
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        //dp[s]表示s这颗树中的最大距离，为零表示这棵树不存在，也就不存在最大距离
        vector<int> dp(1 << n, 0);
        for(int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for(auto &edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            dist[u][v] = 1;
            dist[v][u] = 1;
            dp[(1 << u) | (1 << v)] = 1;
        }

        //求任意两点间的最短距离
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        //s表示了一棵树，s的某个位为1表示这个节点在这棵树中，0表示不在这棵树中
        for(int s = 1; s < (1 << n); ++s) {
            //这是一颗不存在的树，比如树中的某两个节点不存在联通的路径，直接跳过
            if(dp[s] == 0) continue;

            for(int i = 0; i < n; ++i) {
                //树中已经包含了这个节点，或者这个状态已经被计算过了
                if((s & (1 << i)) != 0 || dp[s | (1 << i)] != 0) continue;

                //判断i这个节点是否和s这棵树中的某个节点直接相连
                //否则s | (1 << i)这棵树就是不存在的
                for(int k = 0; k < n; ++k) {
                    if((s & (1 << k)) != 0 && dist[k][i] == 1) {
                        dp[s | (1 << i)] = dp[s];
                        break;
                    }
                }
                
                //s | (1 << i)是一颗不存在的树
                if(dp[s | (1 << i)] == 0) continue;

                //s | (1 << i)是一颗存在的树,那么可以从他的dp状态可以通过s这颗更小的树递推得到
                for(int kk = 0; kk < n; ++kk) {
                    //枚举s中的每个节点和新增节点i的距离，其中最大的就是dp[s | (1 << i)]的结果
                    if((s & (1 << kk)) != 0 && dist[kk][i] != INT_MAX) {
                        dp[s | (1 << i)] = max(dp[s | (1 << i)], dist[i][kk]);
                    }
                }
            }
        }

        vector<int> ans(n - 1, 0);

        for(int i = 0; i < (1 << n); ++i) {
            if(dp[i]) {
                ++ans[dp[i] - 1];
            }
        }

        return ans;
    }
};