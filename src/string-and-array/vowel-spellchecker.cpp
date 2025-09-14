class Solution {
 public:
  vector<string> spellchecker(vector<string> &wordlist,
                              vector<string> &queries) {
    for (auto &word : wordlist) {
      words_perferct.insert(word);

      string word_low;
      for (char c : word) {
        word_low += tolower(c);
      }
      if (!words_cap.count(word_low)) {
        words_cap[word_low] = word;
      }
      string word_vow = devowel(word_low);
      if (!words_vow.count(word_vow)) {
        words_vow[word_vow] = word;
      }
    }

    vector<string> ans;
    for (auto &query : queries) {
      ans.emplace_back(solve(query));
    }
    return ans;
  }

 private:
  unordered_set<string> words_perferct;
  unordered_map<string, string> words_cap;
  unordered_map<string, string> words_vow;

  string devowel(string &word) {
    string ans;
    for (char c : word) {
      ans += isVowel(c) ? '*' : c;
    }
    return ans;
  }

  bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  }

  string solve(string query) {
    if (words_perferct.count(query)) {
      return query;
    }

    string queryL;
    for (char c : query) {
      queryL += tolower(c);
    }
    if (words_cap.count(queryL)) {
      return words_cap[queryL];
    }

    string queryVow = devowel(queryL);
    if (words_vow.count(queryVow)) {
      return words_vow[queryVow];
    }

    return "";
  }
};