/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* loop_head = head;
    struct ListNode* loop_tail = head;
    int count = 1;
    unsigned long bias = 0;

    /* Only process at least one node */
    if(head == NULL){
        return NULL;
    }

    /* Get the list size */
    while(loop_tail->next != NULL ){
        loop_tail = loop_tail->next;
        count++;
    }

    /* Make it become a cycle list */
    loop_tail->next = head;

    /* we should mod it because the behavior is the same */
    bias = k%count;
    for(int i = 0; i < count-bias; i++){
        loop_tail = loop_tail->next;
    }

    /* restore to non-cycle list */
    loop_head = loop_tail->next;
    loop_tail->next = NULL;
    return loop_head;
}
