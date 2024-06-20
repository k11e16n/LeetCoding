/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* borrow function from 206. Reverse Linked List */
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

// Function to find the middle of the linked list
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* middle = findMiddle(head);
    struct ListNode* reverseHead = reverseList(middle);
    struct ListNode* p1 = head;
    struct ListNode* p2 = reverseHead;

    while( p1 != middle && p2 != NULL){
        if(p1->val != p2->val){
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}
