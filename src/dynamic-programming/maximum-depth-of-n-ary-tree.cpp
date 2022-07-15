class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;

        int max_height = 0;

        for(auto x : root->children) {
            max_height = max(max_height, maxDepth(x));
        }

        return max_height + 1;
    }
};