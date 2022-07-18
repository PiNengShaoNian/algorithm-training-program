class Solution {
public:
    int ans = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        treeHeight(root);

        return ans;
    }

    //在求树高的时候更新答案即可
    int treeHeight(TreeNode* root) {
        if(root == NULL) return 0;

        int left = treeHeight(root->left);
        int right = treeHeight(root->right);

        //以root为根的树的直径就是左右子树的高度之和
        ans = max(ans, left + right);

        //正常的求树高逻辑
        return max(left, right) + 1;
    }
};