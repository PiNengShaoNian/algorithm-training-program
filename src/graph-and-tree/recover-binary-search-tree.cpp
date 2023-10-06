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
 private:
  TreeNode *pre;
  TreeNode *target1;
  TreeNode *target2;

  void inOrder(TreeNode *node) {
    if (!node) {
      return;
    }

    inOrder(node->left);
    if (pre && pre->val >= node->val) {
      if (!target1) {
        target1 = pre;
        target2 = node;
      } else {
        target2 = node;
      }
    }
    pre = node;
    inOrder(node->right);
  }

 public:
  void recoverTree(TreeNode *root) {
    inOrder(root);

    swap(target1->val, target2->val);
  }
};