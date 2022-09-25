/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }

    //maxPath(root)表示以root为起始节点，由其一个子节点或者空为终止节点能形成的最大路径和
    //这里定义的路径和答案定义的路径不同
    int maxPath(TreeNode *root) {
        if(root == nullptr) return 0;

        int left = maxPath(root->left);
        int right = maxPath(root->right);
        //答案里的路径root可以是中间节点左右两端的节点可以分别处于左右子树中或者为空
        ans = max(ans,
            //其右子树中存在的一条最大路径和 
            max(left, 0) + 
            //其左子树中存在的一条最大路径和
            max(right, 0) + 
            //该路径必须穿过root
            root->val);

        return max(max(left, right), 0) + root->val;
    }
};