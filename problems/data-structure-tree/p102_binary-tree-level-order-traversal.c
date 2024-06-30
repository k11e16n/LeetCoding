/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    
    /* basic check */
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    /* create a queue(we use array here) to store the tree nodes */
    struct TreeNode* queue_array[2000] = {0}; // due to constrain max is 2000
    int queue_head = 0, queue_tail = 0, queue_size = 1; // 0-index, at least one node now so size is 1

    /* create arrays for return */
    int** retArr = NULL;
    int* columnSizes = NULL;
    int retArr_size = 0;

    /* let's roll with default as root node */
    struct TreeNode* curr_node = NULL;
    queue_array[0] = root;
    int nodes_to_dequeue = queue_size;

    while(queue_size != 0 ){
        /* Create am array to store current answer set */
        int* tempArr = malloc(nodes_to_dequeue * sizeof(int*));
        int tempArr_iter = 0;

        /* handle return arrays */
        retArr = realloc(retArr, (retArr_size + 1) * sizeof(int*));
        columnSizes = realloc(columnSizes, (retArr_size + 1) * sizeof(int));;
        columnSizes[retArr_size] = nodes_to_dequeue;
        while(nodes_to_dequeue != 0){
            /* 1. dequeue current numbers of nodes */
            curr_node = queue_array[queue_head++];
            queue_size--;
            nodes_to_dequeue--;

            /* 2. enqueue nodes children */
            if (curr_node->left != NULL){
                queue_array[++queue_tail] = curr_node->left;
                queue_size++;
            }
            if (curr_node->right != NULL){
                queue_array[++queue_tail] = curr_node->right;
                queue_size++;
            }

            /* 3. push dequeue node to answer set */
            tempArr[tempArr_iter++] = curr_node->val;
        }
        /* set size for next round */
        nodes_to_dequeue = queue_size;

        /* Push the set into return array */
        retArr[retArr_size++] = tempArr;
    }

    *returnSize = retArr_size;
    *returnColumnSizes = columnSizes;
    return retArr;
}
