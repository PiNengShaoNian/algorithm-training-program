class Solution {
public:
    //zeroNodeToNodeCount[x] = t;表示标号x为根的子树和为零,并且在他的子树中节点数量为t
    unordered_map<int,int> zeroNodeToNodeCount;
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> nodeIdToChildren(nodes, vector<int>());
        
        for(int i = 1; i < nodes; ++i) {
            nodeIdToChildren[parent[i]].push_back(i);
        }

        dfs(nodeIdToChildren, value, 0);
        int zeroNodeCount = 0; 
        for(auto it : zeroNodeToNodeCount) {
            int node = it.first;
            int p = parent[node];

            while(p != -1) {
                //如果这个节点的祖先节点子树和也为零，我们就只需要累加他的祖先节点就行了
                //在这里直接跳过累加开始下一轮循环
                if(zeroNodeToNodeCount.count(p)) {
                    goto nextLoop;
                }

                p = parent[p];
            }

            zeroNodeCount += it.second;

            nextLoop:;
        }

        return nodes - zeroNodeCount;
    }

    //自定向下计算子树和，和节点数量，并在子树和为零时更新zeroNodeToNodeCount
    pair<int, int> dfs(vector<vector<int>> &tree,vector<int> &value, int root) {
        int count = 1;
        int sum = value[root];

        for(int child : tree[root]) {
            auto p = dfs(tree, value, child);
            count += p.first;
            sum += p.second;
        }

        if(sum == 0) {
            zeroNodeToNodeCount[root] = count;;
        }
        return {count, sum};
    }
};

//上面的做法需要把所有子树和为零的子树全部收集起来，然后在进行累加
//其实没有必要进行收集，直接在dfs中就可以累加出所有符合条件的节点数量
class Solution {
public:
    int zeroNodeCount = 0;
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> nodeIdToChildren(nodes, vector<int>());
        
        for(int i = 1; i < nodes; ++i) {
            nodeIdToChildren[parent[i]].push_back(i);
        }

        dfs(nodeIdToChildren, value, 0);
        
        return nodes - zeroNodeCount;
    }

    pair<int, int> dfs(vector<vector<int>> &tree,vector<int> &value, int root) {
        int count = 1;
        int sum = value[root];

        for(int child : tree[root]) {
            auto p = dfs(tree, value, child);
            count += p.first;
            sum += p.second;
        }

        if(sum == 0) {
            //祖先节点的子树和也可能为0，我们在这里把改子树的节点数量设为零
            //到时候累加祖先节点的时候就不会重复累加改子树了
            zeroNodeCount += count;
            count = 0;
        }
        return {count, sum};
    }
};