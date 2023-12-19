struct Trie {
  bool is_finished;
  Trie *child[26];

  Trie() {
    is_finished = false;
    fill(begin(child), end(child), nullptr);
  }
};

class MagicDictionary {
 public:
  MagicDictionary() { root = new Trie(); }

  void buildDict(vector<string> dictionary) {
    for (auto &&word : dictionary) {
      Trie *cur = root;
      for (char ch : word) {
        int idx = ch - 'a';
        if (!cur->child[idx]) {
          cur->child[idx] = new Trie();
        }
        cur = cur->child[idx];
      }
      cur->is_finished = true;
    }
  }

  bool dfs(string &searchWord, Trie *node, int pos, bool modified) {
    if (pos == searchWord.size()) {
      return modified && node->is_finished;
    }
    int idx = searchWord[pos] - 'a';
    if (node->child[idx]) {
      if (dfs(searchWord, node->child[idx], pos + 1, modified)) {
        return true;
      }
    }
    if (!modified) {
      for (int i = 0; i < 26; i++) {
        if (i != idx && node->child[i]) {
          if (dfs(searchWord, node->child[i], pos + 1, true)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool search(string searchWord) { return dfs(searchWord, root, 0, false); }

 private:
  Trie *root;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */