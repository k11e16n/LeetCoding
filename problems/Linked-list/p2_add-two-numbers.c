/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* p1 = l1;
    struct ListNode* p2 = l2;
    struct ListNode* result_list_head = NULL;
    struct ListNode* result_list_tail = NULL;
    int sum = 0, carry = 0;

    while (p1 != NULL || p2 != NULL || carry != 0) {
        sum = 0 + carry;
        if (p1 != NULL) {
            sum += p1->val;
            p1 = p1->next;
        }
        if (p2 != NULL) {
            sum += p2->val;
            p2 = p2->next;
        }

        /* get carry and current sum */
        carry = sum / 10;
        sum = sum % 10;

        /* Create new node */
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = sum;
        node->next = NULL;

        /* Add node to new list */
        if (result_list_head == NULL) {
            result_list_head = node;
            result_list_tail = node;
        } else {
            result_list_tail->next = node;
            result_list_tail = node;
        }
    }
    return result_list_head;
}
