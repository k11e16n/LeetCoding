/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /* Method 1 :iteratively
  * Method 2 :recursively
 */
#define METHOD 2

#if METHOD == 1
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while( curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
#endif

#if METHOD == 2
struct ListNode* reverseList(struct ListNode* head) {
    /* if one node or empty node */
    if(head == NULL || head->next == NULL){
        return head;
    }

    struct ListNode* next = NULL;
    struct ListNode* newHead = NULL;

    next = head->next;
    newHead = reverseList(head->next);
    head->next = NULL;
    next->next = head;

    return ret;
}
#endif
