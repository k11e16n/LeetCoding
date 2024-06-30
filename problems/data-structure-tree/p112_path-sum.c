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

bool hasPathSum_helper(struct TreeNode* root, int targetSum, int currentSum) {
    if( root == NULL ){
        return false;
    }
    
    currentSum += root->val;

    if( currentSum == targetSum && isLeaf(root)){
        return true;
    }else{
        return (hasPathSum_helper(root->left, targetSum, currentSum) || 
                hasPathSum_helper(root->right, targetSum, currentSum));
    }
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if( root == NULL ){
        return false;
    }

    return hasPathSum_helper(root, targetSum, 0);
}
