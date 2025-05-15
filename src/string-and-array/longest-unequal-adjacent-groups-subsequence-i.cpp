class Solution {
 public:
  vector<string> getLongestSubsequence(vector<string>& words,
                                       vector<int>& groups) {
    vector<string> ans;
    int n = groups.size();
    for (int i = 0; i < n; i++) {
      if (i == n - 1 || groups[i] != groups[i + 1]) {
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};