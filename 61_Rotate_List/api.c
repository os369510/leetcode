/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!k || !head) return head;
    int len = 0, pos = 0, mod = k;
    struct ListNode *tmp = head, *ret = head, *pre = NULL;
    while (tmp){
        tmp = tmp->next;
        len++;
    }
    tmp = head;
    mod = k % len;
    if (!mod) return head;
    pos = len - mod;
    len = 0;
    while (tmp){
        len++;
        if (len == pos){
            ret = tmp->next;
            tmp->next = NULL;
            tmp = ret;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    pre->next = head;
    return ret;
}


