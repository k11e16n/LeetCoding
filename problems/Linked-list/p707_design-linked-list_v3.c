#define SINGLE 0
#define DOUBLE 1
#define DEBUG 0

#if  SINGLE == 1
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
#endif

#if DOUBLE == 1
typedef struct {
    int val;
    struct MyLinkedListNode* prev;
    struct MyLinkedListNode* next;
}MyLinkedListNode;

typedef struct {
    MyLinkedListNode *head;
    MyLinkedListNode *tail;
    int size;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
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

    MyLinkedListNode *new_node = malloc(sizeof(MyLinkedListNode));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(obj->head == NULL){
        obj->head = new_node;
        obj->tail = new_node;
    }else{
        new_node->next = obj->head;
        obj->head->prev = new_node;
        obj->head = new_node;
    }
    obj->size++;

#if DEBUG == 1
    printf("After %s\n", __func__);
    MyLinkedListNode *iNode=obj->head;
    while(iNode!=NULL){
        printf("iNode->val:%d\n", iNode->val);
        iNode=iNode->next;
    }
    printf("\n\n");
#endif
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    if( obj == NULL ){
        return;
    }

    MyLinkedListNode *new_node = malloc(sizeof(MyLinkedListNode));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(obj->tail == NULL){
        obj->head = new_node;
        obj->tail = new_node;
    }else{
        new_node->prev = obj->tail;
        obj->tail->next = new_node;
        obj->tail = new_node;
    }
    obj->size++;

#if DEBUG == 1
    printf("After %s\n", __func__);
    MyLinkedListNode *iNode=obj->head;
    while(iNode!=NULL){
        printf("iNode->val:%d\n", iNode->val);
        iNode=iNode->next;
    }
    printf("\n\n");
#endif
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if( obj == NULL || index > obj->size ){
        return;
    }

#if DEBUG == 1
    printf("[%s] index:%d, obj->size:%d, val:%d\n", __func__, index, obj->size, val);
#endif

    MyLinkedListNode *temp = obj->head;
    MyLinkedListNode *prev = NULL;
    /* Find the index */
    for(int i=0; i<index; i++){
        prev = temp;
        temp = temp->next;
    }

    /* Create the node */
    MyLinkedListNode *new_node = malloc(sizeof(MyLinkedListNode));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(obj->size == 0){ // empty list;
        obj->head = new_node;
        obj->tail = new_node;
    }else if( temp == NULL){ // Last node
        obj->tail->next = new_node;
        new_node->prev = obj->tail;
        obj->tail = new_node;
    }else if( temp == obj->head){ // head
        new_node->next = obj->head;
        obj->head->prev = new_node;
        obj->head = new_node;
    }else{ // middle 
        new_node->next = temp;
        new_node->prev = temp->prev;
        prev->next = new_node;
        temp->prev = new_node;
    }
    obj->size++;

#if DEBUG == 1
    printf("After %s\n", __func__);
    MyLinkedListNode *iNode=obj->head;
    while(iNode!=NULL){
        printf("iNode->val:%d\n", iNode->val);
        iNode=iNode->next;
    }
    printf("\n\n");
#endif
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if( obj == NULL || index >= obj->size ){
        return;
    }

    MyLinkedListNode *temp = obj->head;
    MyLinkedListNode *prev = NULL;
    MyLinkedListNode *next = NULL;
    /* Find the index and assign to temp */
    for(int i=0; i<index; i++){
        prev = temp;
        temp = temp->next;
        next = temp->next;
    }

    /* Delete it */
    if(temp == obj->head){ // head
        obj->head = temp->next;
    }else if (temp == obj->tail){ //tail
        prev->next = NULL;
        obj->tail = prev;
    }else{ // middle
        prev->next = temp->next;
        next = temp->next;
        next->prev = temp->prev;
    }
    free(temp);
    obj->size--;

#if DEBUG == 1
    printf("After %s\n", __func__);
    MyLinkedListNode *iNode=obj->head;
    while(iNode!=NULL){
        printf("iNode->val:%d\n", iNode->val);
        iNode=iNode->next;
    }
    printf("\n\n");
#endif
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
#endif



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
