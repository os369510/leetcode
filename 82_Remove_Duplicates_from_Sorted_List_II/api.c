/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *sub_head = NULL, *ret = NULL, *tmp =head, *pre_head = NULL;
    if (!head) return ret;
    int pre_val = 0, first = 1;
    while (tmp){
        if (pre_val != tmp->val || first){
            first = 0;
            if (!sub_head){
                sub_head = ret = tmp;
            }
            else{
                pre_head = sub_head;
                sub_head->next = tmp;
                sub_head = tmp;
            }
        }
        else{
            sub_head = pre_head;
            if (sub_head && sub_head->next)
                sub_head->next = NULL;
            if (!sub_head)
                ret = NULL;
        }
        pre_val = tmp->val;
        tmp = tmp->next;
    }
    return ret;
}


