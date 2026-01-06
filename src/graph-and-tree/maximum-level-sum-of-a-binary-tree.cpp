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
  vector<int> sum;
  void dfs(TreeNode* node, int level) {
    if (level == sum.size()) {
      sum.push_back(node->val);
    } else {
      sum[level] += node->val;
    }

    if (node->left) {
      dfs(node->left, level + 1);
    }

    if (node->right) {
      dfs(node->right, level + 1);
    }
  }
  int maxLevelSum(TreeNode* root) {
    dfs(root, 0);
    int ans = 0;
    for (int i = 0; i < sum.size(); i++) {
      if (sum[i] > sum[ans]) {
        ans = i;
      }
    }
    return ans + 1;
  }
};