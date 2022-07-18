//和binary-tree-maximum-path-sum一样的思路
class Solution {
public:
    int ans = INT_MIN;
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        longestPath(root);
        return ans - 1;
    }

    //longestPath(root)表示已root为根的二叉树的
    //max(他左侧和他自身能组成最大的同值路径的节点数量,他右侧和他自身能够组成的最大同值路径的节点数量)
    //           4
    //        4      4
    //      4   1
    //这个二叉树的根节点的longestPath(4)就为3，应为根节点4和他的左侧组成的最长同值路径中的节点数量为3
    int longestPath(TreeNode* root) {
        if(root == NULL) return 0;

        int path = 0;
        int left = longestPath(root->left);
        int right = longestPath(root->right);
        int rightVal = root->right && root->val == root->right->val ? right : 0;
        int leftVal = root->left && root->val == root->left->val ? left : 0;
        
        //根据函数的定义用longestPath(left) + longestPath(right) + 1更新答案即可
        //注意要判断他们的值是否相等，相等了才能累加
        ans = max(ans, leftVal + rightVal + 1);
        //根据函数的定义需要返回leftVal和rightVal中的最大值然后加1
        return max(leftVal, rightVal) + 1;
    }
};