class Solution {
  unordered_map<int, int> b2w;
  int bound;

 public:
  Solution(int n, vector<int>& blacklist) {
    int m = blacklist.size();
    bound = n - m;
    unordered_set<int> block;

    for (int b : blacklist) {
      if (b >= bound) {
        block.emplace(b);
      }
    }

    int w = bound;
    // 将[0, n - m)范围的每个黑名单数字映射到[n - m, n - 1]范围内的一个固定的合法数字
    for (int b : blacklist) {
      if (b < bound) {
        while (block.count(w)) {
          w++;
        }

        b2w[b] = w++;
      }
    }
  }

  // 要想相同概率的挑选出n - m个不在黑名单中数字, 只需要考虑等概率在数组的[0, n - m)部分挑选即可
  // 如果在[0, n - m)中挑选时，挑选出来的是个在黑名单的数我们只需要提前将该数字映射到[n - m, n)
  // 范围内的一个合法数字即可
  int pick() {
    int w = rand() % bound;
    return b2w.count(w) ? b2w[w] : w;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */