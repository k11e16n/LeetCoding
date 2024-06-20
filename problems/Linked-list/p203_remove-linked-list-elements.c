/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;

    while(curr != NULL){
        /* delete the match node */
        if(curr->val == val){
            if(curr == head){ // delete head
                head = head->next;
                free(curr);
                curr = head;
            }else{ // delete tail and middle
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
