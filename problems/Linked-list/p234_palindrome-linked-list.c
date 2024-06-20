/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* node = head;
    int count = 0;

    /* get size */
    while(node != NULL){
        node = node->next;
        count++;
    }

    /* create array */
    int *arr = malloc( count * sizeof(int));
    node = head;
    for(int i=0; node != NULL; i++){
        arr[i] = node->val;
        node = node->next;
    }

    /* Compare the array index */
    int mid = count/2;
    for(int i=0; i<mid; i++){
        if(arr[i] != arr[count-i-1]){
            return false;
        }
    }
    return true;
}
