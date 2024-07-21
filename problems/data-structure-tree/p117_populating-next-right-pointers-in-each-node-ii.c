/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

#define MAX_ARR_SIZE 6001
#define METHOD 3

/* bfs */
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

            /* back to bfs method to enqueue */
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

/* iterator method */
#if METHOD == 2
struct Node* newnode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
   
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    node->next = NULL;
    return node;
}

struct Node* connect(struct Node* root) {
   if(root == NULL)
   {
    return NULL;
   }
   struct Node *head = root;

   while(head != NULL)
   {
     struct Node* dummy = newnode(0);
     struct Node* temp = dummy;

     while(head!= NULL)
     {
        if(head->left != NULL)
        {
            temp->next = head->left;
            temp = temp->next;
        }
        if(head->right != NULL)
        {
            temp->next = head->right;
            temp = temp->next;
        }
         head = head->next;

     }
     head = dummy->next;
   }
    return root;
}
#endif


/* Recursive method from internet
 * brilliant!!
 */
#if METHOD == 3
struct Node *a[1024];                                                            
                                                                                 
void                                                                             
_connect(struct Node *root, int level)                                           
{                                                                                   
        if (!root)                                                                  
                return;

        root->next = a[level];
        a[level] = root;

        _connect(root->right, level + 1);
        _connect(root->left, level + 1);                     
}                                                                                
                                                                                 
struct Node* connect(struct Node* root) {
        bzero(a, sizeof(a));

        _connect(root, 0);                                                          
        return root;                                                                
}
#endif
