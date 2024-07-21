/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    /* nothing to do */
    if(root == NULL){
        return NULL;
    }

    /* if p or q is root */
    /* We return the node if we found the p or q */
    if( root == p || root == q ){
        return root;
    }

    struct TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    /* if p and q are in different child */
    if( leftLCA != NULL && rightLCA != NULL ){
        return root;
    }

    /* if p and q are in the same side, return that side */
    if( leftLCA ){
        return leftLCA;
    }else if ( rightLCA ){
        return rightLCA;
    }else{
        return NULL;
    }
}
