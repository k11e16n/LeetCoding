typedef struct {
    int val;
    struct MyLinkedListNode *next;
} MyLinkedListNode;

typedef struct {
    MyLinkedListNode *head;
    MyLinkedListNode *tail;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->tail = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if( obj==NULL || index >= obj->size ){
        return -1;
    }

    MyLinkedListNode *temp = obj->head;
    for ( int i=0; i<index; i++ ){
        temp=temp->next;
    }
    return temp->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    if( obj == NULL ){
        return;
    }

    MyLinkedListNode *node = malloc( sizeof(MyLinkedListNode) );
    node->val = val;
    node->next = obj->head;

    obj->head = node;
    if(obj->tail == NULL){ // empty list should update tail as well
        obj->tail = node;
    }
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if( obj == NULL ){
        return;
    }

    MyLinkedListNode *node = malloc( sizeof(MyLinkedListNode) );
    node->val = val;
    node->next = NULL;

    if(obj->head == NULL){ // empty list should update head as well
        obj->head = node;
    }else{ 
        obj->tail->next=node;  
    }
    obj->tail = node;
    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if( obj == NULL || index > obj->size ){
        return;
    }

    /* find the node before index (thus index -1) */
    MyLinkedListNode *temp = obj->head;    
    for(int i=0; i<index-1; i++){
        temp=temp->next;
    }

    MyLinkedListNode *node = malloc( sizeof(MyLinkedListNode) );
    node->val = val;
    node->next = NULL;

    if(index == 0){ // head case
        myLinkedListAddAtHead(obj, val);
    }else if(temp == obj->tail){ // tail case
        myLinkedListAddAtTail(obj, val);
    }else{ // middle case
        node->next=temp->next;
        temp->next=node;
        obj->size++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if( obj == NULL || index >= obj->size ){
        return;
    }

    /* find the node and the node before index  */
    MyLinkedListNode *temp = obj->head;
    MyLinkedListNode *prev = obj->head;
    for(int i=0; i<index; i++){
        prev=temp;
        temp=temp->next;
    }

    if(index == 0){ // head case
        obj->head = obj->head->next;
        if(obj->head == NULL ){ // only one node case
            obj->tail = NULL;
        }
    }else{ // middle case
        if(temp == obj->tail){ // tail case
            obj->tail = prev;
        }
        prev->next = temp->next;
    }
    free(temp);
    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    if( obj == NULL ){
        return;
    }

    MyLinkedListNode *temp = obj->head;
    obj->tail = NULL;
    while(obj->head != NULL){
        obj->head = obj->head->next;
        free(temp);
        temp = obj->head;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
