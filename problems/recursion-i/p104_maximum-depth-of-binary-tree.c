/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }else{
        int left, right;
        left=maxDepth(root->left)+1;
        right=maxDepth(root->right)+1;
        return (left>right)?left:right;
    }
}
