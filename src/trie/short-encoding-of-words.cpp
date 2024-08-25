class TrieNode {
 private:
  TrieNode *children[26];

 public:
  // 子节点个数
  int count;
  TrieNode() {
    count = 0;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }

  TrieNode *get(char c) {
    if (children[c] == nullptr) {
      children[c] = new TrieNode();
      count++;
    }
    return children[c];
  }
};

class Solution {
 public:
  int minimumLengthEncoding(vector<string> &words) {
    TrieNode *root = new TrieNode();
    unordered_map<TrieNode *, int> nodeToWordIdx;
    for (int i = 0; i < words.size(); i++) {
      TrieNode *cur = root;
      string &word = words[i];
      for (int j = word.size() - 1; j >= 0; j--) {
        cur = cur->get(word[j] - 'a');
        nodeToWordIdx[cur] = i;
      }
    }

    int ans = 0;
    for (auto [node, idx] : nodeToWordIdx) {
      if (node->count == 0) {
        ans += words[idx].size() + 1;
      }
    }
    return ans;
  }
};