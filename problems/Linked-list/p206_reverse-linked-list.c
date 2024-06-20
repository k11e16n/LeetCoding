/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct Listori_head* ori_head = head;
    struct Listori_head* next = head;
    
    if(head == NULL){
        return NULL;
    }

    while(ori_head->next != NULL){
        next = ori_head->next;
        ori_head->next = next->next;
        next->next = head;
        head = next;
    }
    return head;
}
