class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    unordered_set<int> seen;
    int x = 1 % k;
    while (x && seen.insert(x).second) {
      x = (x * 10 + 1) % k;
    }
    return x ? -1 : seen.size() + 1;
  }
};