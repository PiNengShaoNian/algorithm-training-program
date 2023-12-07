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
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return build(0, nums.size() - 1, nums);
  }

  TreeNode* build(int l, int r, vector<int>& nums) {
    if (l > r) {
      return nullptr;
    }
    if (l == r) {
      return new TreeNode(nums[l]);
    }

    int maxIdx = l;
    for (int i = l + 1; i <= r; i++) {
      if (nums[i] > nums[maxIdx]) {
        maxIdx = i;
      }
    }

    TreeNode* node = new TreeNode(nums[maxIdx]);
    node->left = build(l, maxIdx - 1, nums);
    node->right = build(maxIdx + 1, r, nums);
    return node;
  }
};