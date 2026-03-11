class Solution {
 public:
  int bitwiseComplement(int n) {
    return n ? ((~n) & ((1 << (32 - __builtin_clz(n))) - 1)) : 1;
  }
};