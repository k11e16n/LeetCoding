/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <iostream> 
#include <stack>
#define DEBUG 0

// TODO: Implement a stack by my self

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = NULL;
        Node* curr = head;

        /* Create a stack that store the prev list */
        stack<Node*> stack;

        /* like DFS, we go through one side node first.*/
        while(curr != NULL){
            if(curr->child != NULL){
                temp = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;

                if(temp!=NULL){
                    temp->prev = NULL;
                    stack.push(temp);
#if DEBUG == 1 
                printf("We push %d into stack\n", temp->val);
#endif
                }
            }
            
            if(curr->next == NULL && stack.size() != 0){
                temp = curr;
                curr = stack.top();
#if DEBUG == 1
                printf("We pop %d from stack\n", curr->val);
#endif
                temp->next = curr;
                if(curr!=NULL){
                    curr->prev = temp;
                }
                stack.pop();
            }else{
                curr = curr->next;
            }
        }

#if DEBUG == 1
        temp = head;
        while(temp!=NULL){
            if(temp->prev == NULL){
                printf("NULL");
            }else{
                printf("%d", temp->prev->val);
            }
            printf(":%d:", temp->val);
            if(temp->next == NULL){
                printf("NULL\n");
            }else{
                printf("%d\n", temp->next->val);
            }
            temp = temp->next;
        }
#endif

        return head;
    }
};
