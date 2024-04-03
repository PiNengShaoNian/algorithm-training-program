class Solution {
 public:
  string shiftingLetters(string s, vector<int>& shifts) {
    int n = s.size();
    vector<int> presum(n);
    presum[n - 1] = shifts[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      presum[i] = (shifts[i] + presum[i + 1]) % 26;
    }
    string ans = s;
    for (int i = 0; i < n; i++) {
      ans[i] = 97 + ((s[i] - 97 + presum[i]) % 26);
    }
    return ans;
  }
};