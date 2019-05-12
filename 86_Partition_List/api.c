/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *pre_less = NULL, *head_less = NULL, *tmp = head;
    struct ListNode *pre_great = NULL, *head_great = NULL;
    if (!head || !head->next) return head;
    while (tmp)
    {
        if (tmp->val < x){
            if (!head_less){
                pre_less = head_less = tmp;
            }
            else{
                pre_less->next = tmp;
                pre_less = tmp;
            }
        }
        else{
            if (!pre_great){
                pre_great = head_great = tmp;
            }
            else{
                pre_great->next = tmp;
                pre_great = tmp;
            }
        }
        tmp = tmp->next;
    }
    if (head_less)
        pre_less->next = head_great;
    else
        head_less = head_great;
    if (head_great)
        pre_great->next = NULL;
    return head_less;
}


