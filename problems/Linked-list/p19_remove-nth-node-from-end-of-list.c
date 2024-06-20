/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *temp=head;
    struct ListNode *prev=head;
    int count=0;
    
    /* get list count */
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }

    /* get index to delete from head 
     * index is one-index.
    */
    count = count - n;

    temp=head;
    /* delete the first node */
    if (count == 0){
        head=head->next;
        free(temp);
        return head;
    }

    /* find the previous node for index */
    for(int i=1; i<=count; i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;
}
