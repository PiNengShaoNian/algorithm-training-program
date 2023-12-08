/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int calcDepth(TreeNode *node) {
    if (!node) {
      return 0;
    }

    return max(calcDepth(node->left), calcDepth(node->right)) + 1;
  }

  void dfs(vector<vector<string>> &res, TreeNode *root, int r, int c,
           const int &height) {
    res[r][c] = to_string(root->val);
    if (root->left) {
      dfs(res, root->left, r + 1, c - (1 << (height - r - 1)), height);
    }
    if (root->right) {
      dfs(res, root->right, r + 1, c + (1 << (height - r - 1)), height);
    }
  }

  vector<vector<string>> printTree(TreeNode *root) {
    int m = calcDepth(root);
    int n = (1 << m) - 1;
    vector<vector<string>> res(m, vector<string>(n, ""));
    dfs(res, root, 0, (n - 1) / 2, m - 1);
    return res;
  }
};