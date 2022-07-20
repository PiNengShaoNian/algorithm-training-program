//和largest-bst-subtree一样的思路，不过info现在不存节点数量而是存二叉树的累计和
//因为结点的值有负数，所以把标记无效节点的魔法值从0变为INT_MIN
class Solution {
public:
    int ans = INT_MIN;
    int maxSumBST(TreeNode* root) {
        if(!root) return 0;

        int info[3];
        dfs(root, info);
        return ans < 0 ? 0 : ans;
    }

    //info[0] = sum
    //info[1] = l
    //info[2] = r
    void dfs(TreeNode *root, int info[]) {
        if(!info) {
            info[0] = info[1] = info[2] = 0;
            return;
        }

        int l = root->val;
        int r = root->val;
        int sum = root->val;

        int valid = 1;
        if(root->left) {
            int leftInfo[3];
            dfs(root->left, leftInfo);
            if(leftInfo[0] == INT_MIN || root->val <= leftInfo[2]) {
                valid = 0;
            }
            else {
                ans = max(ans, leftInfo[0]);
                l = leftInfo[1];
                sum += leftInfo[0];
            }
        }

        if(root->right) {
            int rightInfo[3];

            dfs(root->right, rightInfo);
            if(rightInfo[0] == INT_MIN || root->val >= rightInfo[1]) {
                valid = 0;
            }
            else {
                ans = max(ans, rightInfo[0]);
                r = rightInfo[2];
                sum += rightInfo[0];
            }
        }

        if(valid) {
            info[0] = sum;
            info[1] = l;
            info[2] = r;
            ans = max(ans, sum);
        }
        else {
            info[0] = info[1] = info[2] = INT_MIN;
        }
    }
};