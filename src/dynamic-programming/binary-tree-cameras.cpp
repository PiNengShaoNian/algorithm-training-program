class Solution {
public:
    //最少需要放置的摄像头树量
    int count = 0;
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;

         int state = dfs(root);

         if(state == 0) {
             //root还没有被覆盖，需要放置一个摄像头
             ++count;
         }

         return count;
    }

    //0: 没有被覆盖到
    //1: 被覆盖到了，但是没有放置摄像头
    //2: 被覆盖到了, 并且放置摄像头
    int dfs(TreeNode *root) {
        //空节点让他为覆盖状态
        if(!root) return 1;

        //叶子节点，选择不放摄像头，让父节点放，能覆盖更多节点
        if(root->left == NULL && root->right == NULL) {
            return 0;
        }

        int leftState = dfs(root->left);
        int rightState = dfs(root->right);

        //如果有一个子节点没有被覆盖到，则必须在root着放一个
        if(leftState == 0 || rightState == 0) {
            ++count;
            //放了一个后，此时的状态为2
            return 2;
        }

        //左右节点中有一个放置了摄像头，则在root着可以不放置了
        if(leftState == 2 || rightState == 2) {
            return 1;
        }

        //左右节点都被覆盖了，但是root本身还没有被覆盖，但是不直接在它本身
        //放置，而是返回零，让他的父节点放置能覆盖更多的节点
        return 0;
    }
};