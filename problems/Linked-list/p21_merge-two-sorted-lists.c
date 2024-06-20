/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    struct ListNode* node_to_add = NULL;
    struct ListNode* finalListTail = NULL;
    struct ListNode* finalListHead = NULL;

    while (p1 != NULL || p2 != NULL) {
        /* find the node to add within two lists */
        if (p1 == NULL){
            node_to_add = p2;
            p2 = p2->next;
        }else if (p2 == NULL){
            node_to_add = p1;
            p1 = p1->next;
        }else{
            if(p1->val > p2->val){
                node_to_add = p2;
                p2 = p2->next;
            }else{
                node_to_add = p1;
                p1 = p1->next;
            }
        }

        if (finalListHead == NULL) { // if head we need initialize
            finalListTail = node_to_add;
            finalListHead = node_to_add;
        }else{
            finalListTail->next = node_to_add;
            finalListTail = node_to_add;
        }
        node_to_add->next = NULL;
    }
    return finalListHead;
}
