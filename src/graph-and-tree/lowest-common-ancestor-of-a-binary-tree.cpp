/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<int, TreeNode*> valToParent;

        dfs(root, valToParent);

        unordered_set<TreeNode*> seenNodes;

        while(p) {
            seenNodes.insert(p);
            auto it = valToParent.find(p->val);
            if(it != valToParent.end()) {
                p = it->second;
            }
            else {
                break;
            }
        }

        if(!q) return nullptr;

        while(seenNodes.find(q) == seenNodes.end()) {
            q = valToParent[q->val];
        } 

        return q;
    }

    void dfs(TreeNode* root, unordered_map<int, TreeNode*> &valToParent) {
        if(root == nullptr) {
            return;
        }

        if(root->left) {
            valToParent[root->left->val] = root;
            dfs(root->left, valToParent);
        }

        if(root->right) {
            valToParent[root->right->val] = root;
            dfs(root->right, valToParent);
        }
    }
};