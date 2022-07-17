class Solution {
public:
    vector<int> nodeI;
    vector<int> distI;
    vector<vector<int>> graph;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //nodeI[I]表示以0为根的树中，以I为根的子树的节点数量
        nodeI = vector<int>(n, 1);
        //第一趟和第二趟的dfs他的含义不同
        //(1)第一趟: 在以0为根的树中，以i为根的子树中，节点i离他子树中节点的距离和
        //(2)第二趟: 节点i离其他节点的距离和
        distI = vector<int>(n, 0);
        graph = vector<vector<int>>(n);

        for(auto &edge : edges) {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        postOrder(0,-1);
        preOrder(0,-1);

        return distI;
    }

    //计算以node为根的树的距离和
    void postOrder(int vertex, int parent) {
        for(int neighbor : graph[vertex]) {
            if(neighbor == parent) continue;

            postOrder(neighbor, vertex);
            //对于以vertex为根的子树来说，他的节点数量只要简单的累加他的子节点
            //x的nodeI[x]即可
            nodeI[vertex] += nodeI[neighbor];
            //对于以vertex为根的子树来说，他的距离和除了要的累加他的子节点子树的距离和
            //这些子树中的所有路径为了到达vertex本身每条路径的长度还需要加上1
            //比如 1  --->   2  ---> 3，要求distI[1]除了要加上distI[2]外，还要为
            //其中的每条路径加上1，其中有两条路径一条是1到2的
            //一条是1到3的所以distI[1] += distI[2] + 2
            distI[vertex] += nodeI[neighbor] + distI[neighbor];
        }
    }

   //结合现有的信息，算出node离所有节点的距离和
    void preOrder(int vertex, int parent) {
        for(int neighbor : graph[vertex]) {
            if(neighbor == parent) continue;

            //第一轮结束后，只有distI[0]计算的结果才是满足最终答案的(因为我们是以0为根开始计算的)
            //我们可以自顶向下用distI[0]里这个正确答案算出其他节点的最终答案
            //执行到这distI[vertex]已经是正确的答案，对于distI[neighbor]，我们可以用distI[vertex]中的
            //正确答案算出来，相比vertex来说，neighbor到他子树中的每个节点的距离都会少1，但是到他子树外的节点
            //的距离都会大1，其中他子树中的节点数量为nodeI[neighbor]，他子树外的节点数为(graph.size() - nodeI[neighbor])
            //所以我们可以用下面的公式算出distI[neighbor]的正确答案
            distI[neighbor] = distI[vertex] - nodeI[neighbor] + (graph.size() - nodeI[neighbor]);
            preOrder(neighbor, vertex);
        }
    }
};