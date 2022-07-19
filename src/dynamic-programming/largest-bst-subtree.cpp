class Solution {
public:
	int ans = 1;
	int largestBSTSubtree(TreeNode* root) {
		if (root == NULL) return 0;
		int info[3];
		largestBST(root, info);
		return ans;
	}

	//info[0]: 以root为根节点的子BST，他的树节点数量
	//info[1]: min 以root为根节点的子BST，他的树中最小的节点的值
	//info[2]: max 以root为根节点的子BST，他的树中最大的节点的值
	void largestBST(TreeNode* root, int info[]) {
		if (!root) {
			info[0] = info[1] = info[2] = 0;
			return;
		}

		if (root->left == NULL && root->right == NULL) {
			info[0] = 1;
			info[1] = root->val;
			info[2] = root->val;
			return;
		}

		int leftInfo[3];
		largestBST(root->left, leftInfo);
		int rightInfo[3];
		largestBST(root->right, rightInfo);
		
        //如果发现左右子树非空，但是他们不是BST，那么以root为根的子树也不会是BST
		if ((root->left && leftInfo[0] == 0) || (root->right && rightInfo[0] == 0)) {
			info[0] = info[1] = info[2] = 0;
			return;
		}
        
        //左子树为空，且右子树为BST
		if (root->left == NULL && root->val < rightInfo[1]) {
            //root的val值比右子树的最小值还要小，那么root可以和右子树组成更大的BST
			info[0] = rightInfo[0] + 1;
            //当前BST中的最小节点就是root本身
			info[1] = root->val;
            //当前BST中的最大节点就是右子树的最大节点
			info[2] = rightInfo[2];
			ans = max(ans, info[0]);
		}
        //右子树为空，且左子树为BST
		else if (root->right == NULL && root->val > leftInfo[2]) {
			//root的值比左子树的最大值还要大，那么root可以和左子树组成更大的BST
            info[0] = leftInfo[0] + 1;
            //当前BST中的最小节点就是左子树的最小节点
			info[1] = leftInfo[1];
            //当前BST中的最大节点就是root本身
			info[2] = root->val;
			ans = max(ans, info[0]);
		}
        //左右子树都是BST
		else if (root->left && root->right && root->val > leftInfo[2] && root->val < rightInfo[1]) {
			//root的值比左子树的最大值还要大，且比右子树的最小值还要小，那么root可以和左右子树组成更大的BST
            info[0] = leftInfo[0] + rightInfo[0] + 1;
            //当前BST中的最小节点就是左子树的最小节点
			info[1] = leftInfo[1];
            //当前BST中的最大节点就是右子树的最大节点
			info[2] = rightInfo[2];
			ans = max(ans, info[0]);
			return;
		}
		else {
            //虽然左右子树都是BST但是root不能和他们组成更大的BST
			info[0] = info[1] = info[2] = 0;
			return;
		}
	}

    //简化逻辑
    //info[0]: 以root为根节点的子BST，他的树节点数量
	//info[1]: min 以root为根节点的子BST，他的树中最小的节点的值
	//info[2]: max 以root为根节点的子BST，他的树中最大的节点的值
	void largestBST1(TreeNode* root, int info[]) {
		if (!root) {
			info[0] = info[1] = info[2] = 0;
			return;
		}

        info[0] = 1;
        info[1] = info[2] = root->val;
        int valid = 1;
        if(root->left) {
            int leftInfo[3];

		    largestBST(root->left, leftInfo);
            if(leftInfo[0] != 0 && root->val > leftInfo[2]) {
                info[0] += leftInfo[0];
                info[1] = leftInfo[1];
            }
            else {
                valid = 0;
            }
        }

        if(root->right) {
            int rightInfo[3];
            largestBST(root->right, rightInfo);
            if(rightInfo[0] != 0 && root->val < rightInfo[1]) {
                info[0] += rightInfo[0];
                info[2] = rightInfo[2];
            }
            else {
                valid = 0;
            }
        }
		
        if(!valid) {
            info[0] = info[1] = info[2] = 0;
        }
        else {
            ans = max(ans, info[0]);
        }
	}
};