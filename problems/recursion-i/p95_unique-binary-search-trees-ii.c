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

/* Helper for create node */
struct TreeNode* createNode(int val){
    struct TreeNode* new_node = malloc( sizeof(struct TreeNode) );
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct TreeNode** allPossibleBST(int start, int end, int* returnSize) {
    
    int ret_trees_size = 0;
    struct TreeNode** ret_trees = NULL;

    /* Base case */
    if(start > end){
        ret_trees = malloc(sizeof(struct TreeNode*));
        *returnSize = 1;
        ret_trees[0] = NULL;
        return ret_trees;
    }

    /* Let each i become root to generate all possibility */
    printf("about to create, start:%d, end:%d\n", start, end);
    for(int i = start; i <= end; i++){
        int left_subtree_size = 0;
        int right_subtree_size = 0;
        struct TreeNode** left_subtrees = allPossibleBST(start, i-1, &left_subtree_size);
        struct TreeNode** right_subtrees = allPossibleBST(i+1, end, &right_subtree_size);
        
        /* combine all by connect i as root and each left/right child */
        for(int left = 0; left < left_subtree_size; left++){
            for(int right = 0; right < right_subtree_size; right++){
                /* Make a new root node and get one left/right sub tree from subtrees */
                struct TreeNode* root = createNode(i);
                root->left = left_subtrees[left];
                root->right = right_subtrees[right];

                /* enlarge the size and put the new combination in the result array */
                printf("combine, size:%d [%d/%d]-root[%d]-[%d/%d]\n", ret_trees_size, left, left_subtree_size, i, right, right_subtree_size);
                ret_trees = realloc(ret_trees, (ret_trees_size + 1) * sizeof(struct TreeNode*));
                ret_trees[ret_trees_size] = root;
                ret_trees_size++;
            }
        }

    }
    *returnSize = ret_trees_size;
    return ret_trees;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    if(n == 0){
        *returnSize = 0;
        return NULL;
    }
    return allPossibleBST(1, n, returnSize);
}
