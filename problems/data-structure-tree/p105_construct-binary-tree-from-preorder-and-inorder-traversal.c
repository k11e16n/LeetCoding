/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    
    /* Create Node */
    struct TreeNode *root_node = malloc(sizeof(struct TreeNode));
    root_node->val = preorder[0]; // the first preorder should be the root
    root_node->left = NULL;
    root_node->right = NULL;

    /* if there is only one node then nothing to do */
    if(preorderSize == 1){
        return root_node;
    }

    /* find it in inorder position */
    int i = 0;
    for(i = 0; i<inorderSize; i++){
        if(root_node->val == inorder[i]){
            break;
        }
    }

    /* We use inorder to define left and right child infomation */
    int left_inorder_size = i;
    int right_inorder_size = inorderSize - i - 1;

    /* build left and pass the corresponding in/post order */
    if(left_inorder_size){
        root_node->left = buildTree((preorder+1), left_inorder_size, inorder, left_inorder_size);
    }

    /* build right and pass the corresponding in/post order */
    if(right_inorder_size){
        root_node->right = buildTree((preorder+left_inorder_size+1), right_inorder_size, (inorder+left_inorder_size+1), right_inorder_size);
    }

    return root_node;
}
