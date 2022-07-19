class Solution {
public:
    unordered_map<long long, vector<int>> memo;
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        return max(dp(root, 0), dp(root, 1));
    }

    // dp(root, 1)表示打劫时，打劫root能获得的最大收益
    // dp(root, 1)表示打劫时，不打劫root能获得的最大收益
    // 因为有记忆化的开销，所以速度和空间复杂度都不好看
    int dp(TreeNode *root, int pick) {
        if(root == nullptr) return 0;

        long long key = (long long)root;
        auto it = memo.find(key);
        if(it != memo.end() && it->second[pick] != -1) {
            return it->second[pick];
        }
        else {
            memo.emplace(key, vector<int>(2,-1));
        }
        
        int ans = 0;
        if(pick) {
            ans = root->val + dp(root->left, 0) + dp(root->right, 0);
        }
        else {
            ans = max(dp(root->left, 0), dp(root->left, 1)) + max(dp(root->right, 0), dp(root->right, 1));
        }

        memo[key][pick] = ans;
        return ans;
    }

    //改造dp递推方式，现在每个状态只会访问一次，所以不需要进行记忆化
    int rob1(TreeNode* root) {
        if(root == nullptr) return 0;
        int info[2];
        dp1(root, info);

        return max(info[0], info[1]);
    }

    //info[0]表示打劫时，打劫root能获得的最大收益
    //info[1]表示打劫时，不打劫root能获得的最大收益
    void dp1(TreeNode *root, int info[]) {
        if(root == nullptr) {
            info[0] = info[1] = 0;
            return;
        };

        int leftInfo[2];
        dp1(root->left, leftInfo);
        int rightInfo[2];
        dp1(root->right, rightInfo);

        info[0] = root->val + leftInfo[1] + rightInfo[1];
        info[1] = max(leftInfo[0], leftInfo[1]) + max(rightInfo[0], rightInfo[1]);
    }
};