class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        dp(root, 0, 0);
        dp(root, 0, 1);
        return ans;
    }

    //pick = 0,  当前要么只能选左节点，要么就从头开始一条路径
    //pick = 1,  当前要么只能选右节点，要么就从头开始一条路径
    void dp(TreeNode *root, int len, int pick) {
        if(!root) return;

        if(pick) {
            //选右节点,延续当前当前路径len加1
            dp(root->right, len + 1, 0);
            //不选右节点，只能从root开始构建一条路径，重置len
            dp(root->left, 1, 1);
        }
        else {
            //选左节点，延续当前当前路径len加1
            dp(root->left, len + 1, 1);
            //不选左节点，只能从root开始构建一条路径，重置len
            dp(root->right, 1, 0);
        }
        
        ans = max(len, ans);
    }
};