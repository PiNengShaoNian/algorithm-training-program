
//https://leetcode.cn/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-leetcode-/453643
// 这题目的难点在于理解题意和转化题意。
// 我们可以结合 数组的最大子数组和 的思路去解题。

// 1. 「可以从任意节点出发, 到达任意节点」 的路径, 
//    一定是先上升（ 0 ～ n 个）节点, 到达顶点, 后下降（ 0 ～ n 个）节点。
//    我们可以通过枚举顶点的方式来枚举路径。
   
// 2. 我们枚举顶点时, 可以把路径分拆成3部分： 左侧路径、右侧路径和顶点。
//    如下面的路径, 顶点为 20, 左侧路径为 6 -> 15, 右侧为 6 -> 7。
   
//       -10
//       / \
//      9 [20]
//        /  \
//      [15] [7]
//      /    / \
//    [6]   4  [6]   

//    以当前节点为顶点的路径中, 最大和为 两侧路径的最大和 + 节点的值。
//    需要注意的是, 两侧路径也可能不选, 此时取 0。

// 3. 如何求两侧路径最大和？ 看一个类似问题：求数组的最大子数组和。
//    动态规划： dp[i] 代表以 nums[i] 为结尾的子数组的最大和。
//    转移方程： dp[i] = max(dp[i-1], 0) + nums[i]。

// 4. 在树上, 设 dp[C] 代表以当前节点为结尾的最大上升路径和, 
//    则我们需要对节点的左右子树做一个选择, 有
//    dp[C] = max(max(dp[L], 0), max(dp[R], 0)) + C.val
//    式中, C,L,R 分别代指 当前节点、左子节点、右子节点。

// 5. 最后, 以当前节点为顶点的路径中, 最大的和为
//    max(dp[L], 0) + max(dp[R], 0) + C.val。
//    我们枚举顶点, 并记录最大答案。
class Solution {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath(root);
        return ans;
    }

    int maxPath(TreeNode* root) {
        if(root == NULL) return 0;

        int left = maxPath(root->left);
        int right = maxPath(root->right);

        ans = max(ans, max(left, 0) + max(right, 0) + root->val);

        return max(max(left, right), 0) + root->val;
    }
};