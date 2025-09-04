class Solution {
 public:
  int findClosest(int x, int y, int z) {
    int dis1 = abs(x - z);
    int dis2 = abs(y - z);
    if (dis1 == dis2) {
      return 0;
    }
    return dis1 < dis2 ? 1 : 2;
  }
};