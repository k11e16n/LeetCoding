/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* even_list_head = NULL;
    struct ListNode* even_list_tail = NULL;
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    int i = 1;

    if (head == NULL) {
        return NULL;
    }

    /* search for each node */
    while (curr != NULL) {

        if (i % 2) { /* odd index: update */
            prev = curr;
            curr = curr->next;

        } else { /* even index: delete and add to even_list_head*/
            prev->next = curr->next;
            if (even_list_head == NULL) { /* even list is empty, update head and tail */
                even_list_head = curr;
                even_list_tail = curr;
                even_list_tail->next = NULL;
            } else { /* even list is not empty, add at tail */
                even_list_tail->next = curr;
                curr->next = NULL;
                even_list_tail = curr;
            }
            curr = prev->next;
        }
        i++;
    }

    /* plug even_list_head to the tail of the odd list */
    prev->next = even_list_head;

    return head;
}
