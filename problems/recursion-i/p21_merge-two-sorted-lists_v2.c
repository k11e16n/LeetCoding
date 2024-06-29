/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    /* edge case */
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }else if(list1 == NULL){
        return list2;
    }else if(list2 == NULL){
        return list1;
    }

    /* create a node */
    struct ListNode* temp_node = malloc(sizeof(struct ListNode));

    /* Find a next node */
    if(list1->val > list2->val){
        temp_node->val = list2->val;
        temp_node->next = mergeTwoLists(list1, list2->next);
    }else{
        temp_node->val = list1->val;
        temp_node->next = mergeTwoLists(list1->next, list2);
    }

    return temp_node;
}
