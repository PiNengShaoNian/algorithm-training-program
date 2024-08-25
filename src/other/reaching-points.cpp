class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    // 因为tx,ty的范围都是正整数，对于给定任意tx,
    // ty其前驱节点都是固定的，有以下三种情况
    // 1). 如果 tx=ty，不存在上一个状态，状态(tx,ty) 即为起点状态；
    // 2). 如果 tx>ty，则上一个状态是 (tx−ty,ty)
    // 3). 如果 tx<ty，则上一个状态是(tx,ty−tx)。
    // 相反如果从前往后递推每个节点都有两个后继，状态膨胀的非常快
    while (tx >= sx && ty >= sy) {
      if (tx == sx && ty == sy) {
        return true;
      }

      if (tx > ty) {
        // 只要tx还大于ty就只能通过减小tx到达其前驱节点
        // 在这里可以优化逻辑一次性直接减去(tx - sx) / ty个ty
        tx -= max((tx - sx) / ty, 1) * ty;
      } else {
        // 与上面同理
        ty -= max((ty - sy) / tx, 1) * tx;
      }
    }
    return false;
  }
};