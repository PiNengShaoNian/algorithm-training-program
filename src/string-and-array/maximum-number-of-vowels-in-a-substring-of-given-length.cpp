class Solution {
 public:
  int maxVowels(string s, int k) {
    int n = s.size();
    int hash[127] = {0};
    hash['a'] = hash['e'] = hash['i'] = hash['o'] = hash['u'] = 1;
    if (n < k) {
      return 0;
    }
    int r = -1;
    int cnt = 0;
    int ans = 0;
    for (int l = 0; l + k - 1 < n; l++) {
      while (r + 1 < n && (r + 1 - l + 1) <= k) {
        cnt += hash[s[r + 1]] ? 1 : 0;
        r++;
      }

      ans = max(ans, cnt);
      cnt -= hash[s[l]] ? 1 : 0;
    }

    return ans;
  }
};