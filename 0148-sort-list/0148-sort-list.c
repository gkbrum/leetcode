/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode node;

node *merge(node *left, node *right){
    node dummy;
    dummy.val = 0;
    dummy.next = NULL;

    node *tail = &dummy;

    while(left != NULL && right != NULL){
        
        if(left->val < right->val){
            tail->next = left;
            left = left->next;        
        }else{
            tail->next = right;
            right = right->next;  
        }
        tail = tail->next;
    }

    if (left != NULL) {
        tail->next = left;
    } else {
        tail->next = right;
    }

    return dummy.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }

    //divdir a lista em 2 para fazer o merge
    
    //esqueci do ponteiro prev
    node *slow = head;
    node *fast = head;
    node *prev = NULL;

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL;
    }

    node *left = head;
    node *right = slow;

    node *sortedLeft = sortList(left);
    node *sortedRight = sortList(right);

    return merge(sortedLeft, sortedRight);

}