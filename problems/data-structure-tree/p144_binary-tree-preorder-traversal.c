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

#define METHOD 2 // 1: recursive, 2: Iterative
#if METHOD == 1
int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    /* Base case */
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    /* node exists, let's put it into return array */
    int resArrSize = 0, left_sub_child_size = 0, right_sub_child_size  = 0, i = 0;
    int *left_sub_child = NULL, *right_sub_child = NULL;

    /* Get each child info first */
    left_sub_child = preorderTraversal(root->left, &left_sub_child_size);
    right_sub_child = preorderTraversal(root->right, &right_sub_child_size);

    /* Lets start add nodes by order sequence */
    resArrSize = left_sub_child_size + right_sub_child_size + 1;
    int *resArr = realloc( resArr, resArrSize * sizeof(int) );

    /* Add root */
    resArr[i] = root->val;

    /* Add left */
    for(i = 0; i<left_sub_child_size; i++){
        resArr[i+1] = left_sub_child[i];
    }

    /* Add right */
    for(i = 0; i<right_sub_child_size; i++){
        resArr[left_sub_child_size+1+i] = right_sub_child[i];
    }

    *returnSize = resArrSize;
    return resArr;
}
#endif

#if METHOD == 2
/* Idea use a stack(array) to store non-finish node. */
int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    /* basic check */
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    /* Create a stack to store the node, size is 100 due to constraints */
    struct TreeNode* stack_nodes[100] = {0};
    struct TreeNode* curr_node = root;
    int* retArr = NULL;
    int stack_size = 1; //because at least one node now
    int retArr_size = 0;

    while(stack_size != 0){
        if(curr_node != NULL){
            retArr = realloc (retArr, (retArr_size + 1) * sizeof(int));
            retArr[retArr_size++] = curr_node->val;
            /* Check is right has child, then push into stack */
            if(curr_node->right != NULL ){
                stack_nodes[stack_size++] = curr_node->right;
            }
            /* and we go left first */
            curr_node = curr_node->left;
        }else{
            /* lets check the stack now */
            curr_node = stack_nodes[--stack_size];
        }
    }
    
    *returnSize = retArr_size;
    return retArr;
}
#endif

/* Some solution in better coding style for recursive */
int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void preorderTraversalHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (root == NULL) return;

    result[(*returnSize)++] = root->val;
    preorderTraversalHelper(root->left, result, returnSize);
    preorderTraversalHelper(root->right, result, returnSize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int nodeCount = countNodes(root);
    int* result = (int*)malloc(sizeof(int) * nodeCount);

    preorderTraversalHelper(root, result, returnSize);

    return result;
}

