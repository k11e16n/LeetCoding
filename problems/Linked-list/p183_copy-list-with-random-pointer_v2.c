/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* createNode(int val, struct Node* next, struct Node* random){
    struct Node* new = (struct Node* )malloc(sizeof(struct Node));
    new->val = val;
    new->next = next;
    new->random = random;

    return new;
}

struct Node* copyRandomList(struct Node* head) {
	if(!head) return NULL;
    
    struct Node* ptr = head;
    struct Node* new;

//PK Step 1 : First Interviewing , create a new node just next to original node A -> A' -> B -> B' etc
    while(ptr){

      new = createNode(ptr->val, NULL, NULL);
      
      new->next = ptr->next;
      ptr->next = new;

      ptr = new->next;
    }

//PK Step2: Now link the random pointer of new nodes now just update the random ptr of A', B' abd C'
    ptr = head;

    while(ptr){

        ptr->next->random = (ptr->random) ? ptr->random->next : NULL;
        ptr = ptr->next->next;

    }

//PK step3: Now seperate the list new one and old one by at the same time adjusting next of new and old list

    struct Node* ret = head->next;

    struct Node* oldList = head;
    struct Node* newList = head->next;

    while(oldList){

        oldList->next = (oldList->next) ? oldList->next->next : NULL;
        newList->next = (newList->next) ? newList->next->next : NULL;

        oldList = oldList->next;
        newList = newList->next;
    }

    return ret;

}
