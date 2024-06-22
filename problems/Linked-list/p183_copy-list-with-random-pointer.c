/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
	struct Node* node = head;
    struct Node* newlist_head = NULL;
    struct Node* newlist_temp = NULL;
    int size = 0;
    int test = 0;

    /* We duplicate a new_list with val and next copyed */
    while(node != NULL){
        /* Create new node and initialize */
        struct Node* new_node = malloc(sizeof(struct Node));
        new_node->val = node->val;
        new_node->next = NULL;
        new_node->random = NULL;

        /* new list iterator
         * newlist_temp here means previous node of new_node
        */
        if(size == 0){
            newlist_head = new_node;
            newlist_temp = new_node;
        }else{
            newlist_temp->next = new_node;
            newlist_temp = new_node;
        }

        /* ori list iterator */
        node = node->next;
        size++;
    }
    /* determine the random 
     * node here means the iterator of ori list
     * newlist_temp here means the iterator of new_list
    */
    node = head;
    newlist_temp = newlist_head;
    int index = 0;
    struct Node* node_iter = NULL;
    while(node != NULL){
        index = 0;
        node_iter = node->random;

        while(node_iter != NULL){
            node_iter = node_iter->next;
            index++;
        }
        index = size - index;

        /* Update random */
        node_iter = newlist_head;
        for(int i = 0; i<index; i++){
            node_iter = node_iter->next;
        }
        newlist_temp->random = node_iter;

        /* both iterator move on */
        newlist_temp=newlist_temp->next;
        node = node->next;
    }

    return newlist_head;
}
