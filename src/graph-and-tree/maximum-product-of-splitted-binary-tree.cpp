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
  int MOD = 1000000007;
  unordered_map<TreeNode*, int> nodeToSum;
  int dfs(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    }

    int sum = node->val + dfs(node->left) + dfs(node->right);
    nodeToSum[node] = sum;
    return sum;
  }

  int maxProduct(TreeNode* root) {
    dfs(root);

    long long ans = 0;
    int sum = nodeToSum[root];
    for (auto&& pair : nodeToSum) {
      ans = max(ans, (((sum - pair.second * 1LL)) * pair.second));
    }
    return ans % MOD;
  }
};