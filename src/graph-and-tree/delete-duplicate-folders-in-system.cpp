struct TrieNode {
  unordered_map<string, TrieNode *> son;
  string name;
  bool deleted = false;
};

class Solution {
 public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
    TrieNode *root = new TrieNode();
    for (auto &path : paths) {
      TrieNode *cur = root;
      for (auto &s : path) {
        if (!cur->son.contains(s)) {
          cur->son[s] = new TrieNode();
        }
        cur = cur->son[s];
        cur->name = s;
      }
    }

    unordered_map<string, TrieNode *> expr_to_node;

    auto gen_expr = [&](this auto &&gen_expr, TrieNode *node) -> string {
      if (node->son.empty()) {
        return node->name;
      }

      vector<string> expr;
      for (auto &[_, son] : node->son) {
        expr.emplace_back("(" + gen_expr(son) + ")");
      }
      ranges::sort(expr);

      string sub_tree_expr;
      for (auto &e : expr) {
        sub_tree_expr += e;
      }
      if (expr_to_node.contains(sub_tree_expr)) {
        expr_to_node[sub_tree_expr]->deleted = true;
        node->deleted = true;
      } else {
        expr_to_node[sub_tree_expr] = node;
      }

      return node->name + sub_tree_expr;
    };

    for (auto &[_, son] : root->son) {
      gen_expr(son);
    }

    vector<vector<string>> ans;
    vector<string> path;

    auto dfs = [&](this auto &&dfs, TrieNode *node) -> void {
      if (node->deleted) {
        return;
      }

      path.push_back(node->name);
      ans.push_back(path);
      for (auto &[_, son] : node->son) {
        dfs(son);
      }
      path.pop_back();
    };

    for (auto &[_, son] : root->son) {
      dfs(son);
    }

    return ans;
  }
};