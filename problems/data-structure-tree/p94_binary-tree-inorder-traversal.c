/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    
    /* Base case */
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    /* node exists, let's put it into return array */
    int resArrSize = 0, left_sub_child_size = 0, right_sub_child_size  = 0, i = 0;
    int *left_sub_child = NULL, *right_sub_child = NULL;

    /* Get each child info first */
    left_sub_child = inorderTraversal(root->left, &left_sub_child_size);
    right_sub_child = inorderTraversal(root->right, &right_sub_child_size);

    /* Lets start add nodes by order sequence */
    resArrSize = left_sub_child_size + right_sub_child_size + 1;
    int *resArr = realloc( resArr, resArrSize * sizeof(int) );

    /* Add left */
    for(i = 0; i<left_sub_child_size; i++){
        resArr[i] = left_sub_child[i];
    }

    /* Add root */
    resArr[i] = root->val;

    /* Add right */
    for(i = 0; i<right_sub_child_size; i++){
        resArr[left_sub_child_size+1+i] = right_sub_child[i];
    }

    *returnSize = resArrSize;
    return resArr;
}



/* My better method */
void node_inorder(struct TreeNode* root, int** retArr, int* retArrSize){
    if(root == NULL){
        return;
    }

    node_inorder(root->left, retArr, retArrSize);
    *retArr = realloc(*retArr, ((*retArrSize)+1) * sizeof(int));
    (*retArr)[(*retArrSize)++] = root->val;
    node_inorder(root->right, retArr, retArrSize);
}
