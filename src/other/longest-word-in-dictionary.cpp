class Solution {
 public:
  string longestWord(vector<string> &words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
      return a.size() != b.size() ? a.size() < b.size() : a > b;
    });
    string longest;
    unordered_set<string> candidates = {""};
    for (const auto &word : words) {
      if (candidates.count(word.substr(0, word.size() - 1))) {
        candidates.emplace(word);
        longest = word;
      }
    }
    return longest;
  }
};