class Solution {
 public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    std::function<int(int)> find = [&](int x) -> int {
      if (fa[x] == x) {
        return x;
      } else {
        return fa[x] = find(fa[x]);
      }
    };
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);
    // 造成冲突的边(使一个节点拥有两个父节点)
    int conflict = -1;
    // 加入该边后会形成环的边
    int cycle = -1;
    for (int i = 0; i < n; i++) {
      vector<int>& edge = edges[i];
      int from = edge[0];
      int to = edge[1];
      if (parent[to] != to) {
        conflict = i;
      } else {
        parent[to] = from;
        int p1 = find(from);
        int p2 = find(to);
        if (p1 == p2) {
          cycle = i;
        } else {
          fa[p2] = p1;
        }
      }
    }

    if (conflict > -1) {
      if (cycle > -1) {
        /**
         * 有环有冲突 [[1,2],[2,3],[3,1],[4,2]]
         * <===========
         * |           |
         * ▽          |
         * 1 ==> 2 ==> 3
         *       ^
         *       |
         *       4
         * 冗余边为造成冲突那条边([4, 2])的后继节点和它的另一个父节点组成的边即[1, 2]
         */
        return vector<int>{parent[edges[conflict][1]], edges[conflict][1]};
      }
      /**
       * 无环有冲突 [[1,2],[1,3],[2,3]]
       * 1 ==> 2
       * |     |
       * ▽    |
       * 3 <===
       * 冗余边为最后那条加入造成冲突的边即[2, 3]
       */
      return vector<int>{edges[conflict][0], edges[conflict][1]};
    } else {
      /**
       * 有环无冲突 [[1,2],[2,3],[3,1]]
       * <===========
       * |           |
       * ▽          |
       * 1 ==> 2 ==> 3
       * 冗余边为最后加入那条会造成环的边即[3, 1]
       */
      return vector<int>{edges[cycle][0], edges[cycle][1]};
    }
  }
};