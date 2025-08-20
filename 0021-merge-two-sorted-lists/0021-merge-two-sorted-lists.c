/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode node;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    node merged;
    merged.val = 0;
    merged.next = NULL;

    node *tail = &merged;
    while(list1 && list2){
        if(list1->val < list2->val){
            tail->next = list1;
            list1 = list1->next;
        }else{
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if(list1){
        tail->next = list1;
    }else{
        tail->next = list2;
    }
    return merged.next;
}