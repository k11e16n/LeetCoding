/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isLeaf(struct TreeNode* node){
    return (node->left == NULL && node->right == NULL)?true:false;
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
    if( root == NULL ){
        return false;
    }

    if( isLeaf (root) ){
        return (targetSum == root->val);
    }else{
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
}
