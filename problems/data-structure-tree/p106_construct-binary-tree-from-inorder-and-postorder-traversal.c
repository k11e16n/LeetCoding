/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    
    /*Create a node */
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1]; // The last one in postorder is root
    root->left = NULL;
    root->right = NULL;

    /* Do nothing with last node */
    if(inorderSize == 1){
        return root;
    }

    /* find the position in inorder */
    int i = 0;
    for(i = 0; i < inorderSize; i++){
        if(root->val == inorder[i]){
            break;
        }
    }

    /* calculate */
    int left_inorder_size = i;
    int right_inorder_size = inorderSize - i - 1;

    /* construct the left and right nodes */
    if(left_inorder_size){
        root->left = buildTree( inorder, left_inorder_size, postorder, left_inorder_size);
    }
    if(right_inorder_size){
        root->right = buildTree( (inorder + left_inorder_size + 1), right_inorder_size, (postorder + left_inorder_size), right_inorder_size);
    }

    return root;
}
