class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize != 0) {
      return false;
    }
    sort(hand.begin(), hand.end());
    unordered_map<int, int> cnt;
    for (int x : hand) {
      cnt[x]++;
    }

    for (int x : hand) {
      // x已经分配完了
      if (!cnt.count(x)) {
        continue;
      }

      // 由于已经排过序此时x是改组中最小的元素
      // 查看该组中其他元素是否存在如果发现不存在的就返回false
      for (int j = 0; j < groupSize; j++) {
        int num = x + j;
        if (!cnt.count(num)) {
          return false;
        }
        cnt[num]--;
        if (cnt[num] == 0) {
          cnt.erase(num);
        }
      }
    }
    return true;
  }
};