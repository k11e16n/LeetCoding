//#define DEBUG
typedef struct {
    int val;
    struct MyLinkedListNode *next;
}MyLinkedListNode;

typedef struct {
    int MyListSize;
    MyLinkedListNode *head;
    MyLinkedListNode *tail;
} MyLinkedList;

void printStatus(MyLinkedList* obj){
    if(obj==NULL){
        printf("obj is NULL\n");
    }else{
        MyLinkedListNode *temp=obj->head;
        int i=0;
        printf("Status [Size:%d]===\n", obj->MyListSize);
        while(temp != NULL && i<index){
            printf("Node[%d]=%d, %s next\n", i, temp->val, (temp->next==NULL)?"No":"Has");
            temp=temp->next;
            i++;
        }
        printf("Status done ===\n");
    }
}


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *newList=malloc(sizeof(MyLinkedList));
    newList->head=NULL;
    newList->tail=NULL;
    newList->MyListSize=0;
    return newList;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedListNode *temp=obj->head;
    int i=0;

    if(obj==NULL){
        return -1;
    }

    while(temp != NULL && i<index){
        temp=temp->next;
        i++;
    }

    if(temp!=NULL){
        return temp->val;
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedListNode *node=malloc(sizeof(MyLinkedListNode));
    node->val = val;
    node->next = obj->head;
    
    obj->head=node;
    if(obj->tail==NULL){
        obj->tail = node;
    }
    obj->MyListSize++;
#ifdef DEBUG
    printf("After add head (%d)\n", val);
    printStatus(obj);
#endif
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedListNode *node=malloc(sizeof(MyLinkedListNode));
    node->val = val;
    node->next = NULL;

    if(obj->tail==NULL){
        obj->head = node;
        obj->tail = node;
    }else{
        obj->tail->next=node;
        obj->tail = node;
    }
    obj->MyListSize++;

#ifdef DEBUG
    printf("After add tail (%d)\n", val);
    printStatus(obj);
#endif
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedListNode *temp=obj->head;
    int i=0;

    /* Check list is not empty and reasonable index */
    if(obj!=NULL && index<=obj->MyListSize ){
        /* Find the node before index */
        while(temp != NULL && i<index-1){
            temp=temp->next;
            i++;
        }

#ifdef DEBUG
        printf("i:%d, index:%d, ListSize:%d, temp->val:%d\n", i, index, obj->MyListSize, temp->val);
#endif

        /* Add node */
        if(index==0){ // if head
            myLinkedListAddAtHead(obj, val);
        }else if(index==obj->MyListSize){ // if tail
            myLinkedListAddAtTail(obj, val);
        }else{ // if middle
            MyLinkedListNode *node=malloc(sizeof(MyLinkedListNode));
            node->val = val;
            node->next = temp->next;
            temp->next = node;
            obj->MyListSize++;
        }
    }
    
#ifdef DEBUG
    printf("After add index (%d)\n", val);
    printStatus(obj);
#endif
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedListNode *temp=obj->head;
    MyLinkedListNode *prev=obj->head;
    int i=0;

#ifdef DEBUG
    printf("(%s)index:%d, ListSize:%d\n", __func__, index, obj->MyListSize);
#endif

    /* Check list is not empty and reasonable index */
    if(obj!=NULL && index<obj->MyListSize){
        /* Find two nodes, temp and prev */
        while(temp != NULL && i<index){
            temp=temp->next;
            if(i<index-1){
               prev=prev->next;
            }
            i++;
        }

#ifdef DEBUG
    printf("(%s) temp->val:%d, prev->val:%d\n", __func__, temp->val, prev->val);
#endif
        /* delete node */
        if(obj->MyListSize==1 && temp == obj->head){ // if head and only one node
            obj->head = NULL;
            obj->tail = NULL;
        }else if(i==0 && temp == obj->head){ // if head
            obj->head = obj->head->next;
        }else if(temp == obj->tail){ // if tail
            prev->next=NULL;
            obj->tail=prev;
        }else if(temp->next != NULL){ // if middle
            prev->next=temp->next;
        }else{
#ifdef DEBUG
    printf("(%s) i:%d, index:%d, ListSize:%d\n", __func__, i, index, obj->MyListSize);
#endif
        }
        obj->MyListSize--;
        free(temp);
    }

#ifdef DEBUG
    printf("After delete index (%d)\n", index);
    printStatus(obj);
#endif
}

void myLinkedListFree(MyLinkedList* obj) {
    for(int i=0; i<obj->MyListSize;i++){
        myLinkedListDeleteAtIndex(obj, i);
    }
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
