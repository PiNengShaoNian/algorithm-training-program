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
  vector<int> nums;
  TreeNode* balanceBST(TreeNode* root) {
    dfs(root);
    return generate(0, nums.size() - 1);
  }

  TreeNode* generate(int l, int r) {
    if (l > r) {
      return nullptr;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }
    int mid = (l + r) >> 1;
    return new TreeNode(nums[mid], generate(l, mid - 1), generate(mid + 1, r));
  }

  void dfs(TreeNode* root) {
    if (!root) {
      return;
    }
    dfs(root->left);
    nums.push_back(root->val);
    dfs(root->right);
  }
};