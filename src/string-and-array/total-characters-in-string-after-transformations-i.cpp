class Solution {
 public:
  int lengthAfterTransformations(string s, int t) {
    vector<int> cnt(26);
    for (char c : s) {
      cnt[c - 'a']++;
    }
    for (int i = 0; i < t; i++) {
      vector<int> nxt(26);
      nxt[0] = cnt[25];
      nxt[1] = (cnt[25] + cnt[0]) % mod;
      for (int j = 2; j <= 25; j++) {
        nxt[j] = cnt[j - 1];
      }
      cnt = move(nxt);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      ans = (ans + cnt[i]) % mod;
    }
    return ans;
  }

 private:
  static constexpr int mod = 1000000007;
};