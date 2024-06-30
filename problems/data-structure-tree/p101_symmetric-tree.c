/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* node_rotate(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* temp;
    temp = node_rotate(root->right);
    ;
    root->right = node_rotate(root->left);
    ;
    root->left = temp;

    return root;
}

bool isSameTree(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }

    if (left == NULL || right == NULL) {
        return false;
    }

    if (left->val == right->val && 
        isSameTree(left->left, right->left) &&
        isSameTree(left->right, right->right)) {
        return true;
    }

    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    /* rotate left tree */
    node_rotate(root->left);

    /* Check is tree same */
    return isSameTree(root->left, root->right);
}
