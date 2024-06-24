/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* temp = head;
    if(head == NULL || head->next == NULL){
        return head;
    }

    temp = temp->next;
    head->next = temp->next;
    temp->next = head;
    head->next = swapPairs(head->next);

    return temp;
}


/* Idea 
To showcase the above guidelines, we give another example on how to solve a problem recursively.

Given a linked list, swap every two adjacent nodes and return its head.

e.g.  for a list 1-> 2 -> 3 -> 4, one should return the head of list as 2 -> 1 -> 4 -> 3.

We define the function to implement as swap(head), where the input parameter head refers to the head of a linked list. The function should return the head of the new linked list that has any adjacent nodes swapped.

Following the guidelines we lay out above, we can implement the function as follows:

    1. First, we swap the first two nodes in the list, i.e. head and head.next;
    2. Then, we call the function self as swap(head.next.next) to swap the rest of the list following the first two nodes.
    3. Finally, we attach the returned head of the sub-list in step (2) with the two nodes swapped in step (1) to form a new linked list.
As an exercise, you can try to implement the solution using the steps we provided above. Click on "Swap Nodes in Pairs" to try to implement the solution yourself.

*/

