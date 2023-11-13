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
  TreeNode *ans;
  int curDepth = -1;
  int findBottomLeftValue(TreeNode *root) {
    dfs(root, 0);
    return ans->val;
  }

  void dfs(TreeNode *root, int depth) {
    if (!root) {
      return;
    }
    if (depth > curDepth) {
      ans = root;
      curDepth = depth;
    }

    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
  }
};