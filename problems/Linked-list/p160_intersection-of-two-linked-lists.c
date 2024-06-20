/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA=headA;
    struct ListNode *pB=headB;

    /* If List A and List B have the same length it will be easy,
     * i.e. pA == pB is the intersection.
     * How to do that is, assume A < B, so B should move B-A steps in advance
     * and switch to headA/headB could do the trick
    */
    while (pA!=pB){
        pA = (pA==NULL)? headB : pA->next;
        pB = (pB==NULL)? headA : pB->next;
    }
    return pA;
}
