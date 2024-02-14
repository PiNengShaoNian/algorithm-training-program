class Solution {
 public:
  string customSortString(string order, string s) {
    vector<int> freq(26);
    for (char ch : s) {
      freq[ch - 'a']++;
    }
    string ans;
    for (char ch : order) {
      if (freq[ch - 'a'] > 0) {
        ans += string(freq[ch - 'a'], ch);
        freq[ch - 'a'] = 0;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (freq[i] > 0) {
        ans += string(freq[i], i + 'a');
      }
    }
    return ans;
  }
};