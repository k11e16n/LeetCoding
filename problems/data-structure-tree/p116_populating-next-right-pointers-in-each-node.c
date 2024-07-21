/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

#define MAX_ARR_SIZE 4096

#define METHOD 2 /* 1: bfs, 2: recursive */

#if METHOD == 1
struct Node* connect(struct Node* root) {
	if(root == NULL){
        return NULL;
    }

    /* Using an array as queue */
    struct Node* queue[MAX_ARR_SIZE] = {0};
    int front = 0, rare = 0, queue_size = 0;

    /* and let's put root inside as default */
    queue[rare++] = root;
    queue_size++;
    root->next = NULL;
    int num_for_process = 1;

    /* bfs */
    while(queue_size){
        while(num_for_process){
            struct Node *temp = queue[front++];
            queue_size--;
            num_for_process--;

            /* process */
            if(num_for_process >= 1){
                temp->next = queue[front];
            }else{
                temp->next = NULL;
            }

            if(temp->left != NULL){
                queue[rare++] = temp->left;
                queue_size++;
            }
            if(temp->right != NULL){
                queue[rare++] = temp->right;
                queue_size++;
            }
        }
        num_for_process = queue_size;
    }
    return root;
}
#endif

#if METHOD == 2
struct Node* connect(struct Node* root) {
	if (!root) return NULL;
    
    if(root->left != NULL) root->left->next = root->right;
    if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;

    connect(root->left);
    connect(root->right);
    return root;
}
#endif
