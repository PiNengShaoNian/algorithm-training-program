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

class Solution {
public:
    //答案节点root满足的条件
    //(1). root或其子树中包含了p,q两个节点
    //(2). 在满足条件(1)的情况下离p,q最近的节点

    //这个函数的返回值定义会根据阶段有所不同
    //在第一个阶段他会尝试在root这颗树种找到p或q并将p,q返回
    //第二阶段在发现第一个满足上面两个条件的节点后(也就是答案)就会返回该节点
    //第三阶段会把找到的节点一路向上传递
    //如果你查看函数的实现就会发现这三个阶段是依次按顺序执行的
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        //第一阶段: 已经在root中找到p或q了，将其返回
        if(root == p || root == q) return root;

        //第一阶段: 在root中找到p,q并将其返回
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //第二阶段:
        //如果left和right有值说明p和q能在root的左右子树中找到(root满足条件(1)),
        //由于是后续遍历的缘故，此时root是满足条件(2)的, 第一阶段完成开始执行阶段二
        if(left && right) {
            return root;
        }

        //第三阶段: 向上传递答案，也有可能是传递的是第一阶段时的p或q
        if(!left) return right;
        if(!right) return left;

        return nullptr;
    }
};