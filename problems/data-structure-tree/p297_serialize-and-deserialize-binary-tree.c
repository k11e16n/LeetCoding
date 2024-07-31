/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Consider BFS with NULL, and using Linklist to implement the queue
 * node(Front) -> node -> node -> node(Rear) -> null
 * we create some function to use
 */

 #define DUMMY -1001
struct TreeNode_Queue_Node{
    struct TreeNode* node;
    struct TreeNode_Queue_Node* next;
};

struct TreeNode_Queue{
    int size;
    struct TreeNode_Queue_Node* front;
    struct TreeNode_Queue_Node* rear;
};

void enqueue(struct TreeNode_Queue* queue, struct TreeNode* input_node){
    /* Put this node into TreeNode Queue */
    struct TreeNode_Queue_Node* new_queue_node = malloc(sizeof(struct TreeNode_Queue_Node));
    new_queue_node->node = input_node;
    new_queue_node->next = NULL;

    /* Update queue */
    if(queue->rear == NULL){
        queue->front = new_queue_node;
    }else{
        queue->rear->next = new_queue_node;
    }
    queue->rear = new_queue_node;
    queue->size++;
}

struct TreeNode* dequeue(struct TreeNode_Queue* queue){
    if(queue->size == 0){
        return NULL;
    }

    /* dequeue from queue front */
    struct TreeNode* dequeue_node = queue->front->node;

    /* Update queue */
    struct TreeNode_Queue_Node* Queue_Node = queue->front;
    queue->front = Queue_Node->next;
    free(Queue_Node);
    queue->size--;

    /* at least one node, so if front become NULL, there is nomore node */
    if(queue->front == NULL){
        queue->rear = NULL;
    }

    /* Return dequeue TreeNode */
    return dequeue_node;
}

struct TreeNode* create_node(int val){
    /* Create a new tree node */
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    if(root == NULL){
        return NULL;
    }

    /* Create a queue */
    struct TreeNode_Queue* queue = malloc(sizeof(struct TreeNode_Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    /* Create a return char array */
    char* retArr = malloc(1);
    retArr[0] = '\0';
    struct TreeNode* dummy_node = create_node(DUMMY);

    /* get BFS, start with root */
    enqueue(queue, root);
    int num_to_process = queue->size;
    while(queue->size && num_to_process){
        /* pop one node from queue */
        struct TreeNode* node = dequeue(queue);
        /* use sprintf to change to char */
        char tmp[16]={0};
        if(node->val == DUMMY){
            /* push "null,\0" to return string if dummy */
            retArr = realloc(retArr, (strlen(retArr) + 6 )*sizeof(char));
            strcat(retArr,"null,");
            continue;
        }else{
            /* put bal to return sting */
            sprintf(tmp, "%d,", node->val);
            retArr = realloc(retArr, (strlen(retArr) + strlen(tmp) + 1) * sizeof(char));
            strcat(retArr, tmp);
        }

        /* enqueue the left/right child */
        if(node->left){
            enqueue(queue, node->left);
        }else if(node->left == NULL){
            enqueue(queue, dummy_node);
        }
        if(node->right){
            enqueue(queue, node->right);
        }else if(node->right == NULL){
            enqueue(queue, dummy_node);
        }
        num_to_process = queue->size;
    }

    /* delete the last common(,) in return array */
    retArr[strlen(retArr)-1] = '\0';
    /* realloc size to len + 1, 1 is for ending '\0' */
    retArr = realloc(retArr, (strlen(retArr)+1) * sizeof(char));

    return retArr;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if(data == NULL){
        return NULL;
    }
    
    /* we use input_string to token, because strtok will modify original data */
    char *token = NULL;
    char *input_string = malloc( (strlen(data) + 1) * sizeof(char) );
    strcpy(input_string, data);
    int num = 0;

    /* Create a queue */
    struct TreeNode_Queue* queue = malloc(sizeof(struct TreeNode_Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;


    /* *Pseudo Code
    enqueue N = get one data from input
    if queue is not empty
        L = get one data from input
        if L
            N->left = L
            L = quque
        R = get one data from input
        if R
            N->right = R
            R = enqueue
    */

    /* Get a data from input as root and enqueue as default, and it won't be NULL  */
    token = strtok(input_string, ",");
    sscanf(token, "%d", &num);
    struct TreeNode* root = create_node(num);
    enqueue(queue, root);

    while(queue->size != 0){
        /* dequque a node to process */
        struct TreeNode* new_node = dequeue(queue);
        
        /* Get one data from input and process for Left */
        token = strtok(NULL, ",");
        if(token){
            if( strcmp (token, "null") != 0){
                sscanf(token, "%d", &num);
                struct TreeNode* left_child = create_node(num);
                new_node->left = left_child;
                enqueue(queue, left_child);
            }
        }

        /* Get one data from input and process for right */
        token = strtok(NULL, ",");
        if(token){
            if( strcmp (token, "null") != 0){
                sscanf(token, "%d", &num);
                struct TreeNode* left_right = create_node(num);
                new_node->right = left_right;
                enqueue(queue, left_right);
            }
        }
    }

    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);

/* Smart method from internet */

int nodeCnt(struct TreeNode* ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    return (nodeCnt(ptr->left) + nodeCnt(ptr->right) + 1);
}

void recordTree(struct TreeNode* ptr, int* arr, int* idx)
{
    if (ptr != NULL)
    {
        arr[(*idx)++] = ptr->val;

        recordTree(ptr->left, arr, idx);
        recordTree(ptr->right, arr, idx);
    }
    else
    {
        arr[(*idx)++] = -2000;
    }
}

char* serialize(struct TreeNode* root)
{
    int cnt = nodeCnt(root);
    int* arr = (int*)malloc(cnt * sizeof(int));
    int idx = 0;
    recordTree(root, arr, &idx);
    return (char*)arr;
}

/** Decodes your encoded data to tree. */
struct TreeNode* buildTree(int* arr, int* idx)
{
    struct TreeNode* node;
    if (arr[(*idx)] == -2000)
    {
        (*idx)++;
        return NULL;
    }
    node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = arr[(*idx)++];
    node->left = buildTree(arr, idx);
    node->right = buildTree(arr, idx);
    return node;
}

struct TreeNode* deserialize(char* data)
{
    int* arr = (int*)data;
    int idx = 0;
    return buildTree(arr, &idx);
}
